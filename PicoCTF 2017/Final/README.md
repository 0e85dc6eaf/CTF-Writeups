# Choose

> Unhappy that you can't choose which enemies to fight? Choose your own adventure! Source. Connect on shell2017.picoctf.com:40492. ASLR is not enabled.

Hints:

> An assumption made in the code is wrong. Which assumption, and what does it allow you to do?

This challenge was rather an easy one (after completing level 4 binary exploitation).

First we can connect to the server manually and fight against some trolls. Killing a troll activates `wizardSight` and since ASLR is disabled, we have to leak stack address only once.

In my case second enemy address is `0xffffdba4`.

Next, let's have a look at the comments:
```c
//TODO: These are all the same size, so remove in future version for brevity
```
Is it true? We can easily check it and it appears that `centaur` and `unicorn` are 4 bytes larger than other enemies (it's because of variables order and the alignment). Luckily `enemies` array has only space for 11 `orcs`, so we have buffer overflow.

Name of the last enemy overlaps with return address. We can use names of the enemies to put our shellcode on stack and return there.

Finding working shellcode was actually the most difficult part. I tried 6 different shellcodes before I found a valid one.

[Final exploit](exploit.py)

The flag is `c9dafc1f416eef55e6e2ba610505a441`.