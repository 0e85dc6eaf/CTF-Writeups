# HashChain

> We found a service hiding a flag! It seems to be using some kind of MD5 Hash Chain authentication to identify who is allowed to see the flag. Maybe there is a flaw you can exploit? hcexample.py has some example code on how to calculate iterations of the MD5 hash chain. Connect to it at shell2017.picoctf.com:2412!

Hints:

> Connect from the shell with nc. Read up on how Hash Chains work and try to identify what could make this cryptosystem weak.

First, let's connect to the server. It asks us if we want to get flag or to register. We need to find out how does the service work, so we choose register option.

```
>ncat shell2017.picoctf.com 2412

*******************************************
***            FlagKeeper 1.1           ***
*  now with HASHCHAIN AUTHENTICATION! XD  *
*******************************************

Would you like to register(r) or get flag(f)?

r/f?

r
Hello new user! Your ID is now 4422 and your assigned hashchain seed is d71f5142463efcf6dc7be216cf4644b5
Please validate your new ID by sending the hash before this one in your hashchain (it will hash to the one I give you):
6c544539f49c479c8a10f9fb83569758
```

We can easily check that seed is just a hash of our ID. (We can search for `md5 4422` in DuckDuckGo to check it)
We can slightly modify the example script to calculate our hash. When the server prompts to authenticate as user XXXX we need to take the ID as seed and hash until we get the same hash as on the screen.
The previous hash will give us the flag.

[Script to calculate the hash](main.py)
```
>main.py
f97656b02c25329cae5389bcd5be3d59
```

```
>ncat shell2017.picoctf.com 2412

*******************************************
***            FlagKeeper 1.1           ***
*  now with HASHCHAIN AUTHENTICATION! XD  *
*******************************************

Would you like to register(r) or get flag(f)?

r/f?

f
This flag only for user 7349
Please authenticate as user 7349
f21f38e0bce0ec1711aca5f7d3beed95
Next token?
f97656b02c25329cae5389bcd5be3d59
Hello user 7349! Here's the flag: 232360dd1aa3dd2f25c6c4ffe1893a06
```

The flag is `232360dd1aa3dd2f25c6c4ffe1893a06`.