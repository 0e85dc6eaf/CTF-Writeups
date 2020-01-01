#!/usr/bin/env python3
plain = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789{}!@#$%^&*()_-+="
cipher = "00 30 20 50 40 70 60 90 80 B0 A0 D0 C0 F0 E0 11 01 31 21 51 41 71 61 91 81 B1 02 32 22 52 42 72 62 92 82 B2 A2 D2 C2 F2 E2 13 03 33 23 53 43 73 63 93 83 B3 15 05 35 25 55 45 75 65 95 85 A1 C1 04 12 24 54 44 F3 74 B4 94 84 E3 C4 A4 C5"
sbox = {c:p for c,p in zip(cipher.split(),plain)}
secret = "11 80 20 E0 22 53 72 A1 01 41 55 20 A0 C0 25 E3 20 30 00 45 05 35 40 65 C1"
print("".join(sbox[c] for c in secret.split()))