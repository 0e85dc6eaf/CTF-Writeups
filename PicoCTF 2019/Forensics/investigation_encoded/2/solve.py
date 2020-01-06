#!/usr/bin/env python3
import string
from Cryptodome.Util.number import bytes_to_long
import ctypes
def getVal(byte):
	idx = byte>>3
	a = idx
	idx2 = 0
	idx2 = idx2 >> 29
	idx = byte
	idx += idx2
	idx &= 7
	idx -= idx2
	b = idx
	kc = key[a]
	r=7-b
	return (kc>>r)&1
data = [0,4,18,40,60,82,100,120,142,158,180,200,218,234,252,270,286,308,328,346,362,370,384,396,410,426,444,456,470,480,490,496,512,522,534,546,560,564]
key = [0x8B,0x0AA,0x2E,0x0EE,0x0E8,0x0BB,0x0AE,0x8E,0x0BB,0x0AE,0x3A,0x0EE,0x8E,0x0EE,0x0A8,0x0EE,0x0AE,0x0E3,0x0AA,0x0E3,0x0AE,0x0BB,0x8B,0x0AE,0x0B8,0x0EA,0x0AE,0x2E,0x0BA,0x2E,0x0AE,0x8A,0x0EE,0x0A3,0x0AB,0x0A3,0x0BB,0x0BB,0x8B,0x0BB,0x0B8,0x0AE,0x0EE,0x2A,0x0EE,0x2E,0x2A,0x0B8,0x0AA,0x8E,0x0AA,0x3B,0x0AA,0x3B,0x0BA,0x8E,0x0A8,0x0EB,0x0A3,0x0A8,0x0AA,0x28,0x0BB,0x0B8,0x0AE,0x2A,0x0E2,0x0EE,0x3A,0x0B8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]

tree = {}
chars = string.ascii_lowercase+string.digits+' '
for idx,c in enumerate(chars):
	if c!=' ':
		eax = idx
		ecx = eax+18
		edx = 0x38E38E39
		eax = ecx
		eax *= edx
		edx = eax//2**32
		eax = eax%2**32
		edx >>= 3
		eax = ecx
		eax >>= 31
		edx -= eax
		eax = edx
		eax <<= 3
		eax += edx
		eax <<= 2
		ecx -= eax
		edx = ecx
		ecx = edx
		ecx >>= 31
		eax = edx
		eax ^= ecx
		eax -= ecx
	else:
		eax = idx
	a = data[eax]
	b = data[eax+1]
	d = ""
	for j in range(a,b):
		d += str(getVal(j))
	node = tree
	for e in d[:-1]:
		if e not in node:
			node[e] = {}
		node = node[e]
	node[d[-1]] = c
text = bin(bytes_to_long(open('output','rb').read()))[2:]
node = tree
flag = ""
for digit in text:
	if node == tree and digit == "0":
		continue
	node = node[digit]
	if type(node) == str:
		flag += node
		node = tree
print(flag)