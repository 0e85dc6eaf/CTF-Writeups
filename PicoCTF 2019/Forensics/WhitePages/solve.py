#!/usr/bin/env python3
from Cryptodome.Util.number import long_to_bytes
f = open('whitepages.txt','rb').read()
out = ""
i = 0
while i < len(f):
	if f[i:i+1] == b'\x20':
		out+="1"
	elif f[i:i+3] == b'\xe2\x80\x83':
		out+="0"
		i+=2
	i+=1
print(long_to_bytes(int(out,2)).decode('utf-8'))