#!/usr/bin/env python3
out = """114
114
114
111
99
107
110
114
110
48
49
49
51
114
""".splitlines()
print("".join([chr(int(x)) for x in out]))