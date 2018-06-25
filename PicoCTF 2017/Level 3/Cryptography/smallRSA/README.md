# smallRSA

> You intercepted a single message. However, it appears to be encrypted. Can you decrypt it? Message

Hints:

> Normally, you pick e and generate d from that. What appears to have happened in this case? What is likely about the size of d?

We can solve this problem using Wiener's attack. There are many implementations of it on Github, but they're mostly forks of [this one](https://github.com/pablocelayes/rsa-wiener-attack) by [pablocelayes](https://github.com/pablocelayes).
For this reason i decided to use this one. All magic happens in this library. We only need to call one function and we get the d value.

```
>python main.py
Hacked!
3223594586826657550897063711914171740995144768727978698812620148084071525621
flag{Are_any_RSA_vals_good_13441315963}
```

The flag is `flag{Are_any_RSA_vals_good_13441315963}`.