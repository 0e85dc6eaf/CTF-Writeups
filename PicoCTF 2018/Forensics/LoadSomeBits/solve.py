#!/usr/bin/env python3
f = open("pico2018-special-logo.bmp","rb").read()[54:] #skip header
flag = ""
bin = ""
for a in f:
	if (a&0b1)==1:
		bin+="1"
	else:
		bin+="0"
	if len(bin)==8:
		char = chr(int(bin,2))
		flag += char
		bin = ""
		if char == "}":
			break
print(flag)