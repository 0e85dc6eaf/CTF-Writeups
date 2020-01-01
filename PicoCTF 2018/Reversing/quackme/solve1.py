#!/usr/bin/env python3
key = b"\x29\x06\x16\x4F\x2B\x35\x30\x1E\x51\x1B\x5B\x14\x4B\x08\x5D\x2B\x5C\x10\x06\x06\x18\x45\x51\x00\x5D"
cipher = b"You have now entered the Duck Web, and you're in for a honk"
flag = "".join(chr(k^c) for k,c in zip(key,cipher[:len(key)]))
print(flag)