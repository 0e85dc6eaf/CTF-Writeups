#!/usr/bin/env python2
from pwn import *
from Crypto.Util.number import long_to_bytes

def egcd(a, b):
    u, u1 = 1, 0
    v, v1 = 0, 1
    g, g1 = a, b
    while g1:
        q = g // g1
        u, u1 = u1, u - q * u1
        v, v1 = v1, v - q * v1
        g, g1 = g1, g - q * g1
    return u, v, g

r = remote('2018shell1.picoctf.com',50652)
r.recvuntil("q : ")
q = int(r.recvline())
r.recvuntil("p : ")
p = int(r.recvline())
r.sendline("Y")
r.sendline("%d"%(p*q))

r.recvuntil("p : ")
p = int(r.recvline())
r.recvuntil("n : ")
n = int(r.recvline())
r.sendline("Y")
r.sendline("%d"%(n//p))

r.recvuntil("e : ")
e = int(r.recvline())
r.recvuntil("n : ")
n = int(r.recvline())
r.sendline("N")

r.recvuntil("q : ")
q = int(r.recvline())
r.recvuntil("p : ")
p = int(r.recvline())
r.sendline("Y")
r.sendline("%d"%((p-1)*(q-1)))

r.recvuntil("plaintext : ")
plain = int(r.recvline())
r.recvuntil("e : ")
e = int(r.recvline())
r.recvuntil("n : ")
n = int(r.recvline())
r.sendline("Y")
r.sendline("%d"%(pow(plain,e,n)))

r.recvuntil("ciphertext : ")
cipher = int(r.recvline())
r.recvuntil("e : ")
e = int(r.recvline())
r.recvuntil("n : ")
n = int(r.recvline())
r.sendline("N")

r.recvuntil("q : ")
q = int(r.recvline())
r.recvuntil("p : ")
p = int(r.recvline())
r.recvuntil("e : ")
e = int(r.recvline())
r.sendline("Y")
r.sendline("%d"%(egcd(e,(p-1)*(q-1)))[0])

r.recvuntil("p : ")
p = int(r.recvline())
r.recvuntil("ciphertext : ")
cipher = int(r.recvline())
r.recvuntil("e : ")
e = int(r.recvline())
r.recvuntil("n : ")
n = int(r.recvline())
r.sendline("Y")
plain = pow(cipher,egcd(e,(p-1)*((n//p)-1))[0]%((p-1)*((n//p)-1)),n)
r.sendline("%d"%plain)
print(long_to_bytes(plain).decode('utf-8'))