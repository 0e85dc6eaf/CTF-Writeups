#!/usr/bin/python

from Crypto.Util.number import *
from flag import FLAG, round

def encrypt(msg):
    assert set(msg) == set(['0', '1'])
    enc = [msg[i:i+2] + str(int(msg[i]) ^ int(msg[min(i+1, len(msg)-1)])) for i in range(0, len(msg), 2)]
    return ''.join(enc)

ENC = bin(bytes_to_long(FLAG))[2:]

for _ in xrange(round):
    ENC = encrypt(ENC)

fp = open('FLAG.enc', 'w')
fp.write(long_to_bytes(int(ENC, 2)))
fp.close()
