#!/usr/bin/env python3
out = """66
79
78
74
79
86
73
""".splitlines()
print("".join([chr(int(x)) for x in out]))