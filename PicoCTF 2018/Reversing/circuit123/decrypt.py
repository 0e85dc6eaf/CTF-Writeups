#!/usr/bin/python2

from hashlib import sha512
import sys

def verify(x, chalbox):
    length, gates, check = chalbox
    b = [(x >> i) & 1 for i in range(length)]
    for name, args in gates:
        if name == 'true':
            b.append(1)
        else:
            u1 = b[args[0][0]] ^ args[0][1]
            u2 = b[args[1][0]] ^ args[1][1]
            if name == 'or':
                b.append(u1 | u2)
            elif name == 'xor':
                b.append(u1 ^ u2)
    return b[check[0]] ^ check[1]
    
def dec(x, w):
    z = int(sha512(str(int(x))).hexdigest(), 16)
    return '{:x}'.format(w ^ z).decode('hex')

if __name__ == '__main__':
    if len(sys.argv) < 3:
        print 'Usage: ' + sys.argv[0] + ' <key> <map.txt>'
        print 'Example: Try Running ' + sys.argv[0] + ' 11443513758266689915 map1.txt'
        exit(1)
    with open(sys.argv[2], 'r') as f:
        cipher, chalbox = eval(f.read())
    
    key = int(sys.argv[1]) % (1 << chalbox[0])
    print 'Attempting to decrypt ' + sys.argv[2] + '...'
    if verify(key, chalbox):
        print 'Congrats the flag for ' + sys.argv[2] + ' is:', dec(key, cipher)
    else:
        print 'Wrong key for ' + sys.argv[2] + '.'
