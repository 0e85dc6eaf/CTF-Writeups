# you can't see me

> '...reading transmission... Y.O.U. .C.A.N.'.T. .S.E.E. .M.E. ...transmission ended...' Maybe something lies in /problems/you-can-t-see-me_4_8bd1412e56df49a3c3757ebeb7ead77f.

Hints:

> What command can see/read files?

> What's in the manual page of ls?

This challenge was pretty fun. If we `ls` the directory we can see a file named `.`.

```
$ cd /problems/you-can-t-see-me_4_8bd1412e56df49a3c3757ebeb7ead77f
$ ls -lA
total 4
-rw-rw-r-- 1 hacksports hacksports 57 Sep 28 08:29 .
```

Single `.` means the current directory and it shouldn't be printed with `ls -lA`...

Let's try to list directory with python.

```
$ python
>>> import os
>>> os.listdir(".")
['.  ']
```

So they named file `.  ` (dot space space). Now we can cat it.
```
$ cat ".  "
picoCTF{j0hn_c3na_paparapaaaaaaa_paparapaaaaaa_22f627d9}
```

Flag is `picoCTF{j0hn_c3na_paparapaaaaaaa_paparapaaaaaa_22f627d9}`.
