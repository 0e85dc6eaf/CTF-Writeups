#!/usr/bin/python2 -u
from hashlib import sha256
from Crypto import Random
from Crypto.Random import random
from Crypto.Cipher import AES
from subprocess import check_output, STDOUT, CalledProcessError

BLOCK_SIZE = 16
R = Random.new()

with open("parameters.txt") as f:
    p = int(f.readline().strip())
    g = int(f.readline().strip())

password = open("password.txt").read()

def pad(m):
    o = BLOCK_SIZE - len(m) % BLOCK_SIZE
    return m + o * chr(o)

def unpad(p):
    return p[0:-ord(p[-1])]

def send_encrypted(KEY, m):
    IV = R.read(BLOCK_SIZE)
    aes = AES.new(KEY, AES.MODE_CBC, IV)
    c = aes.encrypt(pad(m))
    print (IV + c).encode('hex')

def read_encrypted(KEY):
    data = raw_input("").decode('hex')
    IV, data = data[:BLOCK_SIZE], data[BLOCK_SIZE:]
    aes = AES.new(KEY, AES.MODE_CBC, IV)
    m = unpad(aes.decrypt(data))
    return m

def serve_commands(KEY):
    while True:
        cmd = read_encrypted(KEY)
        try:
            output = check_output(cmd, shell=True, stderr=STDOUT)
        except CalledProcessError as e:
            output = str(e) + "\n"
        send_encrypted(KEY, output)

print """Welcome to the
______ _   _   _____ _          _ _ 
|  _  \ | | | /  ___| |        | | |
| | | | |_| | \ `--.| |__   ___| | |
| | | |  _  |  `--. \ '_ \ / _ \ | |
| |/ /| | | | /\__/ / | | |  __/ | |
|___/ \_| |_/ \____/|_| |_|\___|_|_|
"""

print "Parameters:"
print "p = {}".format(p)
print "g = {}".format(g)

a = random.randint(1, 2**46)
A = pow(g, a, p)
print "A = {}".format(A)

B = int(raw_input("Please supply B: "))
K = pow(B, a, p)

KEY = sha256(str(K)).digest()

pw = read_encrypted(KEY)
if pw == password:
    serve_commands(KEY)
else:
    send_encrypted("Invalid password!\n")
