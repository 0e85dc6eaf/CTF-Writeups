# Raw2Hex

> This program just prints a flag in raw form. All we need to do is convert the output to hex and we have it! CLI yourself to /problems/bdb9a442247cf58a0ebcd5d680e868be and turn that Raw2Hex!

Hints:

> Google is always very helpful in these circumstances. In this case, you should be looking for an easy solution.

OK, let's run this program.

```
<username>@shell-web:/problems/bdb9a442247cf58a0ebcd5d680e868be$ ./raw2hex | xxd
0000000: 5468 6520 666c 6167 2069 733a ff9a 4fdb  The flag is:..O.
0000010: 6995 b557 590a 742b 0e68 5bd3            i..WY.t+.h[.
```

To make it even easier we can skip first 12 bytes (`The flag is:`).

```
<username>@shell-web:/problems/bdb9a442247cf58a0ebcd5d680e868be$ ./raw2hex | xxd -s 12 -p
ff9a4fdb6995b557590a742b0e685bd3
```

The flag is `ff9a4fdb6995b557590a742b0e685bd3`.