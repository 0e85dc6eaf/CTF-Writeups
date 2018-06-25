# Neighbour

> For a given large integer n, find the nearest perfect power that is equal or smaller than n.

When we connect to the server we can see that we have to solve captcha first. We can just bruteforce it.
Now we can proceed to real problem. We have to find the largest `x^y` (where ^ stands for exponentation) smaller than given `n`.
We know that `x` must be at least `2`, so our exponent has to be at most log(2,n). Now, for every `i` in range from 2 to floor(log(2,n)) we calculate floor(root(i,n))^i.
The greatest value is the one we're looking for. The last thing we need to do is to subtract it from `n` and submit the difference.
After 10 rounds we get the flag. [Final script](solve.py) [output](output.txt)

Flag: `ASIS{36812f76cce2753e482ac6f68f9d3012}`