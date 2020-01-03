#!/usr/bin/env python3
f1 = open("kitters.jpg","rb").read()
f2 = open("cattos.jpg","rb").read()
flag = ""
for ch1,ch2 in zip(f1,f2):
	if ch1!=ch2:
		flag += chr(ch2)
print(flag)