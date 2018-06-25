# SoRandom

> We found sorandom.py running at shell2017.picoctf.com:23741. It seems to be outputting the flag but randomizing all the characters first. Is there anyway to get back the original flag?

Hints:

> How random can computers be?

As the original app is written in Python it is the best choice to solve this problem in this language. We see that 'encryption' is based only on the seed which is a constant we know...
Let's connect to the server to see randomized flag.
```
>ncat shell2017.picoctf.com 23741
Unguessably Randomized Flag: BNZQ:1l36de9583w5516fv3b8691102224f3e
```

Now we can decode it using simple Python [script](main.py)

For some reason script doesn't work on Windows. But on Windows 10 we can use Linux on Windows and it will work then.
```
$ python main.py
FLAG:8a18af7233c1846ad6e1235654851b2d
```

The flag is `8a18af7233c1846ad6e1235654851b2d`.