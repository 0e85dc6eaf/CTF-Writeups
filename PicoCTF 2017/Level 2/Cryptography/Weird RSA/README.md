# Weird RSA

> We recovered some data. It was labeled as RSA, but what in the world are "dq" and "dp"? Can you decrypt the ciphertext for us?

PicoCTF was the first time when I attempted to solve RSA problems, so I had no idea what dq and dp could be. However, when we search for RSA on wikipedia we can find out it's about Chinese Reminder Theorem and what's more they even showed us how to calculate it ;)
The only problem might be modular operations (modular exponentation and inverse). Python supports natively BigInt and modular exponentation and it's also easy to find modular inverse implementation on stack overflow.

[Script](decrypt.py)

```
>python decrypt.py
Theres_more_than_one_way_to_RSA
```

The flag is `Theres_more_than_one_way_to_RSA`.