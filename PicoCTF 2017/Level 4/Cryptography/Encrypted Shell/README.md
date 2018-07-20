# Encrypted Shell

> This service gives a shell, but it's password protected! We were able intercept this encrypted traffic which may contain a successful password authentication. Can you get shell access and read the contents of flag.txt? The service is running at shell2017.picoctf.com:40209.

Hints:

> Are any of the parameters used in the key exchange weaker than they should be?

First, let's have a look at the source. We can see that `p`,`g`,`A`,`B` parameters are public and `a` (and `b`) is private.
We can read public parameters from pcap file.

The algorithm used for key exchange is Diffie–Hellman key exchange (that's why it's named `DHshell`). 
We can notice that `a` can be at most `2**46` and while it's too big number for brute force, hopefully we can find an algorithm that solves it.

On Wikipedia there's a list of algorithms used for discrete logarithm problem ( https://en.wikipedia.org/wiki/Discrete_logarithm#Algorithms ).
I tried to read the articles about these algorithms and choose the best one, but to be honest I didn't understand them.

I decided to use sagemath to calculate the discrete logarithm and when I was looking for the function name I found out that it supports many of the algorithms listed on Wikipedia.
https://doc.sagemath.org/html/en/reference/groups/sage/groups/generic.html

`discrete_log` and its alias `discrete_log_generic` would be probably too slow.

`discrete_log_rho` doesn't allow us to specify bounds, so it could be too slow (I didn't test it).

`bsgs` and `discrete_log_lambda` both allow us to pass bounds and they work. [bsgs.sage](bsgs.sage) [discrete_log_lambda.sage](discrete_log_lambda.sage)

In my case `a=33657892424673`.

Now we can decrypt rest of pcap file. We can reuse most of the code from original dhshell.py. Messages are hex encoded, so we can conveniently copy paste them from pcap.

[decrypt.py](decrypt.py) (Please note newline at the end)

When we finally have valid password we can build our own client to connect to the server and execute `cat flag.txt` on it.

[exploit.py](exploit.py)

The flag is `ac72f7354114b5b0909ab78812eb58ca`.
