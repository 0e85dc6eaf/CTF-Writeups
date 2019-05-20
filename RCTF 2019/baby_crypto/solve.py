#!/usr/bin/env python2
import sys
import binascii
import hashpumpy
from pwn import *
from paddingoracle import BadPaddingException, PaddingOracle
class PadBuster(PaddingOracle):
	def __init__(self, **kwargs):
		super(PadBuster, self).__init__(**kwargs)
	def oracle(self, data):
		r.sendline(binascii.hexlify(data+"\x00"*20))
		print(binascii.hexlify(data+"\x00"*20))
		data = r.recvuntil("Input your cookie:")
		print(data)
		if "Invalid padding" in data:
			raise BadPaddingException
		if "Invalid hash" in data:
			return
		raise RuntimeError
WANTED_CONTENT = "admin:0;username:admin;password:admin\x80\x00\x00\x00\x00\x00\x00\x00\x00\x01\xa8;admin:1"
r = remote("45.76.208.70",20000)
print(r.recvuntil("Input username:"))
r.sendline("admin")
print(r.recvuntil("Input password:"))
r.sendline("admin")
print(r.recvuntil("Your cookie:"))
data=r.recvuntil("Input your cookie:")
cookie=binascii.unhexlify(data.splitlines()[1].strip())
hash=cookie[-20:]
print(data)
padbuster = PadBuster()
new_cookie = padbuster.encrypt(WANTED_CONTENT,block_size=16,iv=bytearray(16))
print("Cookie",cookie)
print("Hash",binascii.hexlify(hash))
print("New cookie",new_cookie)
print("New hash and data",hashpumpy.hashpump(binascii.hexlify(hash),"admin:0;username:admin;password:admin",";admin:1",16))
new_hash = hashpumpy.hashpump(binascii.hexlify(hash),"admin:0;username:admin;password:admin",";admin:1",16)[0]
r.sendline(binascii.hexlify(new_cookie)+new_hash)
r.interactive()