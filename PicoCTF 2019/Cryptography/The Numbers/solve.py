#!/usr/bin/env python3
from string import ascii_uppercase
flag = [16,9,3,15,3,20,6,"{",20,8,5,14,21,13,2,5,18,19,13,1,19,15,14,"}"]
print("".join(ch if type(ch) == str else ascii_uppercase[ch-1] for ch in flag))