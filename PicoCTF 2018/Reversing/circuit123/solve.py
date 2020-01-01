#!/usr/bin/env python2
from z3 import *
import sys
s = Solver()
cipher, chalbox = eval(open("map2.txt","r").read())
len, gates, check = chalbox
b = [Bool("b[%d]"%x) for x in range(1141)]
s.add(Xor(b[check[0]],check[1]))
ctr = len
max_arg = 1141
for gate in gates:
	if gate[0]=="true":
		s.add(b[ctr]==True)
	elif gate[0]=="xor":
		args = gate[1]
		s.add(b[ctr]==Xor(Xor(b[args[0][0]],args[0][1]),Xor(b[args[1][0]],args[1][1])))
	elif gate[0]=="or":
		args = gate[1]
		s.add(b[ctr]==Or(Xor(b[args[0][0]],args[0][1]),Xor(b[args[1][0]],args[1][1])))
	else:
		print(gate)
		sys.exit(1)
	ctr+=1
key = [None for i in range(len)]
if s.check() == unsat:
	print("Failed")
else:
	result = s.model()
	for i in result:
		if int(i.name()[2:-1])<len:
			key[int(i.name()[2:-1])]=("True" == str(result[i]))
key = key[::-1]
key_int = 0
for k in key:
	key_int<<=1
	key_int+=k
print(key_int)
#238330815915141915202597380416519198885
#picoCTF{36cc0cc10d273941c34694abdb21580d__aw350m3_ari7hm37ic__}