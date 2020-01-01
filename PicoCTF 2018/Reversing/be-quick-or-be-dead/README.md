# be-quick-or-be-dead-1

Our goal in this challenge is to calculate key in a faster way. We don't have to analyze the decryption itself.

When we look at `calculate_key` function we can see that it's a simple loop and the final iterator is a key.

We can patch the application to immediately return the correct key - `3752393848`.

[original application](be-quick-or-be-dead-1.bak)

[patched application](be-quick-or-be-dead-1)

Flag: `picoCTF{why_bother_doing_unnecessary_computation_27f28e71}`

# be-quick-or-be-dead-2

This time `calculate_key` function calls function `fib` with argument `1026`. We can easily guess that `fib` stands for Fibonacci, so the key is 1026th term of Fibonacci Sequence.

[The first 2000 Fibonacci numbers](https://oeis.org/A000045/b000045.txt)

`fib(1026)=11798692818055232550147578884125865608089028544560913468519228968187430794620907976123201977895385245239705082830656904630178314159866370495211539023461052682811230321796555930907722724384131648527339458407317543768`

Of course this number is too large for 32bit register, so the final key is `fib(1026) mod 2**32 = 4144667480`.

Similarly to the previous challenge we can patch the application to immediately return this number.

[original application](be-quick-or-be-dead-2.bak)

[patched application](be-quick-or-be-dead-2)

Flag: `picoCTF{the_fibonacci_sequence_can_be_done_fast_7e188834}`

# be-quick-or-be-dead-3

This time key is equal `calc(100021) mod 2**32` where `calc` function is defined as:
```
calc(x) = calc(x-1) - calc(x-2) + calc(x-3) - calc(x-4) + calc(x-5)*4660 for x >= 5
and calc(x) = x**2 + 9029 for x < 5
```

We can use dynamic programming to quickly compute final key.

[script to compute key](solve.py)

```
$ ./solve.py
572362474
```

Similarly to previous challenges we can patch the application to immediately return this number.

[original application](be-quick-or-be-dead-3.bak)

[patched application](be-quick-or-be-dead-3)

Flag: `picoCTF{dynamic_pr0gramming_ftw_a0b0b7f8}`