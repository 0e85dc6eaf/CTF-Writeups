# rsa-madlibs

In this challenge you just have to answer a few basic questions about RSA.

Equations you need:
```
n = p * q
phi(n) = (p-1) * (q-1) <-- totient(n)
e * d mod phi(n) = 1
plaintext ** e mod n = ciphertext
ciphertext ** d mod n = plaintext
```

[script](solve.py)

Flag: `picoCTF{d0_u_kn0w_th3_w@y_2_RS@_c6724916}`