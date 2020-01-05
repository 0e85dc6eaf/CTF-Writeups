# Need For Speed

In this challenge we can cheat and use gdb (gdb ignores SIGALRM).

```
$ gdb ./need-for-speed-original
### some output ###
gdb-peda$ r
Starting program: ###path###/need-for-speed-original
Keep this thing over 50 mph!
============================

Creating key...

Program received signal SIGALRM, Alarm clock.
Finished
Printing flag:
PICOCTF{Good job keeping bus #0d11d09e speeding along!}
[Inferior 1 (process 32) exited normally]
Warning: not running
```

Alternative solution is to patch `calculate_key` function to return final key immediately.

[patched](need-for-speed)

[original](need-for-speed-original)

Flag: `PICOCTF{Good job keeping bus #0d11d09e speeding along!}`