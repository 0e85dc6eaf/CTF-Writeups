#!/usr/bin/env python2
from pwn import *
p = process("./times-up")
p.recvuntil("Challenge: ")
sol = eval(p.recvline())
p.sendline(str(sol))
p.interactive()