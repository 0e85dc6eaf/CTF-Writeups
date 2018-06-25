# Security by obscurity

We got some strange `password.x.a.b.c.d.e.f.g.h.i.j.k.l.m.n.o.p.a.b.c.d.e.f.g.h.i.j.k.l.m.n.o.p.p.o.n.m.l.k.j.i.h.g.f.e.d.c.b.a.a.b.c.d.e.f.g.h.i.j.k.l.m.n.o.p` file.
```
$ file password[extension]
password[extension]: Zip archive data, at least v2.0 to extract
```
We can use 7-zip to extract it (just click on it until you see password.txt file). Unfortunately the last archive is password protected.
With help of JohnTheRipper hopefully we can crack it.
```
$ zip2john password.zip > hash.txt
$ john hash.txt
```
The password is `asdf`...
The only file in the archive contains flag.

Flag: `CTF{CompressionIsNotEncryption}`