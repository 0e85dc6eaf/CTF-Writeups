# Pupper

We got an custom language interpreter along with its source code and a few examples.
I decided to find a vulnerability without checking the source. From the examples we can learn the syntax.
The language only supports simple ifs, references, functions and coercion. We also know that we can't display private int and there is no way to coerce or assign it to public int.
However we have if instruction and it appears that it allows the branches to be public.
```
let x = flag in
if (x>1)
	then 1
	else 0
```
We can use binary search algorithm to find x in the reasonable amount of time.

[exploit](exploit.py)

Flag: `PCTF{0of_0uch_0wi3_my_IF_$t4t3m3n7s}`