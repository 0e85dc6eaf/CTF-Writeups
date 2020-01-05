#!/usr/bin/env python3
txt = "w1{1wq87g_9654g"
flag = ""
for i in range(len(txt)):
	if i % 2 == 0:
		flag += chr(ord(txt[i])-5)
	else:
		flag += chr(ord(txt[i])+2)
print("picoCTF{%s}"%flag)