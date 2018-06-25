# computeRSA

> RSA encryption/decryption is based on a formula that anyone can find and use, as long as they know the values to plug in. Given the encrypted number 150815, d = 1941, and N = 435979, what is the decrypted number?

Hints:

> decrypted = (encrypted) ^ d mod N

The best way to solve RSA problems is to use Python. In this case we just need to call one function (if we pass 3 arguments to pow function, it does modular exponentation, which is a faster way to calculate a^b%c)

```
>>> pow(150815,1941,435979)
133337
```

The flag is `133337`.