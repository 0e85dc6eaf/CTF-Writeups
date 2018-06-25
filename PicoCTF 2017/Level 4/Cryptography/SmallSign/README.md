# SmallSign

> This service outputs a flag if you can forge an RSA signature! nc shell2017.picoctf.com 27525 smallsign.py

Hints:

> RSA encryption (and decryption) is multiplicative.

We know that `(ab)^c` equals `a^c*b^c`. If we could sign all the primes in requested range we would be able to calculate signature for any number in this range.
Unfortunately we don't know the number in advance and the range is really huge (from 0 to 2**32). There are way too many primes there.
The only thing we can do is to sign as many as we can and hopefully it will work. To generate list of primes I used (primesieve)[https://primesieve.org/].
I was quite unlucky and couldn't the right number for a very long time, but after 30 (or even more) attempts I finally got the flag. (solve.py)[solve.py] (it may run for more than 10 minutes)
```
$ ./solve.py
Congrats! Here is the flag:
 c4061d2c3315e76970f4c70e26a459cf
```


The flag is `c4061d2c3315e76970f4c70e26a459cf`.