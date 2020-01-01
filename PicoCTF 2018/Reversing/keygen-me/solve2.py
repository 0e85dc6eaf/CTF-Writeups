#!/usr/bin/env python2
from z3 import *
import sys
import string
keyspace = string.digits+string.uppercase
x = []
product_key = [""]*16
for i in range(16):
	x.append(Int("%s"%chr(i+65)))
s = Solver()
for i in range(16):
	s.add( And(x[i]>=0,x[i]<=35) )
s.add((x[0]+x[1])%36==14)
s.add((x[2]+x[3])%36==24)
s.add((x[2]-x[0])%36==6)
s.add((x[1]+x[3]+x[5])%36==4)
s.add((x[2]+x[4]+x[6])%36==13)
s.add((x[3]+x[4]+x[5])%36==22)
s.add((x[6]+x[8]+x[10])%36==31)
s.add((x[1]+x[4]+x[7])%36==7)
s.add((x[9]+x[12]+x[15])%36==20)
s.add((x[13]+x[14]+x[15])%36==12)
s.add((x[8]+x[9]+x[10])%36==27)
s.add((x[7]+x[12]+x[13])%36==23)
if unsat==s.check():
	print("failed")
	sys.exit(-1)
result = s.model()
for i in result:
	product_key[ord(i.name())-65]=keyspace[result[i].as_long()]
print("".join(product_key))