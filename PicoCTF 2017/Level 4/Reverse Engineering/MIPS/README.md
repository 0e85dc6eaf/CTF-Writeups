# MIPS

> The modern renaissance man knows of many things, ranging from cyber security, to architecture. Can you prove that you're more than just a computer whiz? mips. Enter the flag as a hexadecimal number, prefixed by 0x

Hints:

> We recommend the SPIM simulator with some extra options enabled.

> The MIPS R2000 architecture uses branch-delay slots.

I downloaded SPIM simulator to see how the program works, however there were too many depedencies between variables, so I decided just to bruteforce the correct value.
I rewrote our assembly to [pseudo code](pseudocode.txt) and then to [C++](solve.cc).
To compile the program use
```
g++ solve.cc -o solve -O2
```
(I used int64_t in main, because if the program failed to find the right value it would be an infinite loop - uint32_t is always less than 2^32)

It takes just a few seconds to get the find the correct input.
```
$ ./solve
0xaf51bf5e
```

The flag is `0xaf51bf5e`.
