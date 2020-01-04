#!/usr/bin/env python3
from Cryptodome.Util.number import long_to_bytes
a = [1096770097,1952395366,1600270708,1601398833,1716808014,1734304823,962880562,895706419]
print("picoCTF{%s}"%"".join([long_to_bytes(x).decode('utf-8') for x in a]))