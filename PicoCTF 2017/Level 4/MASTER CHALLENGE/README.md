# weirderRSA

> Another message encrypted with RSA. It looks like some parameters are missing. Can you still decrypt it? Message

Hints:

> Is there some way to create a multiple of p given the values you have?

> Fermat's Little Theorem may be helpful.

I really liked this challenge. It wasn't easy, but it didn't require any secret knowledge, just some school level maths.
You also need to know how RSA works with Chinese Remainder Theorem (we needed it in one of the previous challenges, but in case you don't remember it, there's a good description on wikipedia https://en.wikipedia.org/wiki/RSA_(cryptosystem)#Using_the_Chinese_remainder_algorithm )
So basically
```
dp = d mod (p-1)
```
Unfortunately, we don't have the remaining values and we can't just calculate plain message.
From the hints we can deduce that there is some way to calculate a multiple of p given the values we have (they wouldn't ask if it was impossible).
In fact we don't have much more data, just public key.
We also know how to calculate values for RSA
```
p*q = n
e*d = 1 (mod phi(n))
```
`phi(n)` is equal `(p-1)(q-1)` and `p-1` is our modulus in previous equation. It's important to note that `e*d = 1 (mod (p-1))` (and `e*d = 1 (mod (q-1))`) too.
It may seem complicated, but in the end it's very intuitive.
```
e*d = 1 (mod (p-1))
e*d - 1 = 0 (mod (p-1))
e*(d mod (p-1)) - 1 = 0 (mod (p-1)) #modular arithmetic allows it
e*dp - 1 = 0 (mod (p-1))
```
It means that `e*dp-1` is divisible by `p-1`, so it's almost a multiple of `p`...
It also means that there exists some integer `m` (in our case positive) that
```
e*dp-1 = m(p-1)
```
At first it may seem impossible to solve. We don't know 2 values and have only one equation, but you have to note that `p` is larger than `dp` (by definition) and in result `m` should be less than `e`.
Because `e` is relatively small, we can bruteforce `m`.
```
p = (e*dp-1)/m+1
```
If `p` divides `n` it means we got the correct value.

[solve.py](solve.py)

```
$ ./solve.py
m=10309
p=20529180105026939663522959912724081085077673061651766016992476274055740940916100206487267305327209055949000972909816496819697144056672018100817931511085671
q=24188545703513084424534330705545289476793595829570059454907464943585766209153680039748095077000338654861314054581955525283436353990964386083652324112273409
d=111699495666495298935254634360346323313381404090976066224868355466244695805084302197153153568785345856734777839768713404592763455866412174329700775754345275533590944631869901678528670977118662506547545544717655364913757785420674464813311593280199094290640522910242971004775588028583962020569735723479816159233
flag{wow_leaking_dp_breaks_rsa?_53102681769}
```

The flag is `flag{wow_leaking_dp_breaks_rsa?_53102681769}`.