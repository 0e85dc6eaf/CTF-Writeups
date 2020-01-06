# B1g_Mac

First let's decompile [the application](main.exe.bak) with [retdec](https://retdec.com/) (with `-k` flag).

The only interesting part of `main` function is `_listdir` call.

```c
_listdir(0, (int32_t)g17);
```

We can see that depending on the first argument `_lisdir` function either calls `_decodeBytes` (a1==1) or `_hideInFile` (a1==0).

If we search for all `_lisdir` calls, we can see that `_decode` function does exactly what we want (decodes the flag and prints it).

We can patch the application to call `_decode` function.

[patched binary](main.exe)

```
>main.exe
Work is done!
value of DECODE picoCTF{M4cTim35!}
Wait for 5 seconds to exit.
```

Alternatively we can analyze `_decodeBytes` function and see that it reads the flag from file modification time. Then we can read needed bytes directly from [b1g_mac.zip](b1g_mac.zip) file.

[script](solve.py)

Flag: `picoCTF{M4cTim35!}`