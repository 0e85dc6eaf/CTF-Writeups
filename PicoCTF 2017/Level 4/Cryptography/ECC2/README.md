# ECC2

> More elliptic curve cryptography fun for everyone! handout.txt (Yes, the flag will just be the number n.)

Hints:

> Using SageMath (or something similar which supports working with elliptic curves) will be very helpful.

In this challenge we are given some elliptic curve parameters as well as coordinates of one point on it.
Calculating B value is trivial as we have only one unknown. [calculateB.py](calculateB.py)
```
B = y^2-x^3-A*x (mod M)
B=25255205054024371783896605039267101837972419055969636393425590261926131199030
```

Now we need to find such `n` that `P'=nP`. Elliptic curves multiplication is simply the repeated addition of point P.
Unfortunately the addition is rather complicated and we cannot easily compute `n` given the values we have.

I tried to use algorithms from previous challenge (`bsgs` and `discrete_log_lambda`) wiht bounds `(0,400000000000000000000000000000)`, but they work in `O(sqrt(n))`, so it still takes too much time to compute `n`.

Eventually, I found `Pohlig–Hellman` algorithm, which allows us to decrease the complexity.

```python
F = GF(93556643250795678718734474880013829509320385402690660619699653921022012489089)
A = 66001598144012865876674115570268990806314506711104521036747533612798434904785
B = 25255205054024371783896605039267101837972419055969636393425590261926131199030
E = EllipticCurve(F,[0,0,0,A,B])
P = E((56027910981442853390816693056740903416379421186644480759538594137486160388926,65533262933617146434438829354623658858649726233622196512439589744498050226926))
Pn = E((61124499720410964164289905006830679547191538609778446060514645905829507254103,2595146854028317060979753545310334521407008629091560515441729386088057610440))
order = E.order()
subresults = []
factors = []
for prime, exponent in factor(order):
	_factor = prime ** exponent
	factors.append(_factor)
	P2 = P*(order//_factor)
	Pn2 = Pn*(order//_factor)
	subresults.append(discrete_log_lambda(Pn2, P2, (0,_factor), '+'))
print(crt(subresults,factors))
```
(I used `Pollard's lambda` instead of `Baby-step giant-step` mentioned on wikipedia, because it uses less memory)

Unfortunately factors of the order are still too big and we can't find discrete logarithm even for them. (the largest one is `1975901744727669147699767`)

However, we haven't use the fact that `n < 400000000000000000000000000000` yet.

If we stop the algorithm when prime factors get too large (let's say one billion), we can see that the result is `152977126447386808276536247114` (which of course doesn't have to be the correct answer).
However, it's almost 1/2 of the upper boundary for `n`. We can add the modulus to it as long as `n` is less than the upper boundary (it shouldn't take too long).
In my case modulus was already greater than the upper boundary, so I didn't have to add anything.

[solve.sage](solve.sage)

The flag is `152977126447386808276536247114`.
