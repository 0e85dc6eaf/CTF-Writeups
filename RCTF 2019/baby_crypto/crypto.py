#!/usr/bin/python3 -u
from cryptography.hazmat.backends import default_backend
from cryptography.hazmat.primitives import padding
from cryptography.hazmat.primitives.ciphers import Cipher, algorithms, modes
from hashlib import sha1
import binascii
import json
import os
import re
import sys

def pad(s):
	padder = padding.PKCS7(128).padder()
	return padder.update(s) + padder.finalize()

def unpad(s):
	unpadder = padding.PKCS7(128).unpadder()
	return unpadder.update(s) + unpadder.finalize()

key = os.urandom(16)
iv = os.urandom(16)
salt = key

iv_len = 16

print("Input username:")
username = sys.stdin.readline().strip()
if not re.match("^[a-z]{5,10}$", username):
	print("Invalid username")
	exit()

print("Input password:")
password = sys.stdin.readline().strip()
if not re.match("^[a-z]{5,10}$", password):
	print("Invalid password")
	exit()

cookie = b"admin:0;username:%s;password:%s" %(username.encode(), password.encode())

h = sha1()
h.update(salt)
h.update(cookie)
hv = h.digest()
hv_hex = h.hexdigest()
hash_len = len(hv)

cookie_padded = pad(cookie)

backend = default_backend()
cipher = Cipher(algorithms.AES(key), modes.CBC(iv), backend=backend)
encryptor = cipher.encryptor()
cookie_padded_encrypted = encryptor.update(cookie_padded) + encryptor.finalize()
print("Your cookie:")
print(binascii.hexlify(iv).decode() + binascii.hexlify(cookie_padded_encrypted).decode() + hv_hex)

def is_valid_hash(cookie, hv):
	h = sha1()
	h.update(salt)
	h.update(cookie)
	return hv == h.digest()

while True:
	try:
		print("Input your cookie:")
		data_hex = sys.stdin.readline().strip()
		data = binascii.unhexlify(data_hex)
		assert(len(data) > iv_len + hash_len)
		iv, cookie_padded_encrypted, hv = data[:iv_len], data[iv_len: -hash_len], data[-hash_len:]
		cipher = Cipher(algorithms.AES(key), modes.CBC(iv), backend=backend)
		decryptor = cipher.decryptor()
		cookie_padded = decryptor.update(cookie_padded_encrypted) + decryptor.finalize()
		try:
			cookie = unpad(cookie_padded)
		except Exception as e:
			print("Invalid padding")
			continue
		if not is_valid_hash(cookie, hv):
			print("Invalid hash")
			continue
		info = {}
		for _ in cookie.split(b";"):
			k, v = _.split(b":")
			info[k] = v
		if info[b"admin"] == b"1":
			with open("flag") as f:
				flag = f.read()
				print("Your flag: %s" %flag)
		else:
			print("Goodbye nobody")
		exit()
	except Exception as e:
		print("Invalid cookie %s" %e)
