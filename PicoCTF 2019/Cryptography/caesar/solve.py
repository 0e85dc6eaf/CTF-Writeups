#!/usr/bin/env python3
enc = "jyvzzpunaolybipjvunfzpthre"
for i in range(26):
	flag = ""
	for c in enc:
		flag += chr((ord(c)-97+i)%26+97)
	print("%d: picoCTF{%s}"%(i,flag))