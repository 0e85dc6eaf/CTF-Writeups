# Poetry

Again we got only the binary, but this it has an additional protection - stack canary. The problem with it is that even if we find buffer overflow vulnerability somewhere it will only return to the address on stack if the stack cookie is valid.
When we connect to the server we can see that we have shell as `user` (like in filter env challenge) and we have to read flag in /home/poetry, which is only accessible by user `poetry`.

The binary doesn't seem to read anything from stdin, so it's time to analyse it in IDA.
First it gets the value of `LD_BIND_NOW` which according to https://linux.die.net/man/8/ld-linux forces the dynamic linker to resolve all symbols on start (normally it resolves them when they are referenced for the first time).

If the variable is set, it checks if we passed an argument (argc==2) to the program, if we did it does strcpy, else it quits.
After strcpy the program does syscall. According to [this table](https://filippo.io/linux-syscall-table/) it is exit_group, so buffer overflow is not exploitable.

I tried to exploit it the easy way (using LD_PRELOAD), but then I realized that it is statically linked, so no cheating...
Let's go back to the case `LD_BIND_NOW` is not set. It calls readlink("/proc/self/exe"), sets `LD_BIND_NOW` and executes the program again.

What looks suspiciously is that the binary could just pass its path to execve, why does it reads link?
I searched for `readlink /proc/self/exe` and the second result was https://stackoverflow.com/questions/28953307/how-to-handle-readlink-of-proc-self-exe-when-executable-is-replaced-during

Thanks to this question I find out that /proc/self/exe can point to `/original/path (deleted)` eventually, but our application does not check it.

So if we remove our application before it reads /proc/self/exe and create a file named `poetry (deleted)` it will execute this one.
As we can't remove application in poetry directory, we need to create a copy. Simple `cp` won't work here, because it's no longer SUID binary (and we're owners).

Symbolic link didn't work either (proc/self/exe points to real binary, not our link).
In the end it works for hard links.
```
ln -s /bin/cat '/home/user/poetry (deleted)'
ln /home/poetry/poetry /home/user/poetry
(/home/user/poetry /home/poetry/flag &);rm /home/user/poetry
```
[exploit.py](exploit.py)

Flag: `CTF{CV3-2009-1894}`
