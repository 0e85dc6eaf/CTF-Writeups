# Holey beep

*For this task we need the exploit from previous challenge*

What we need to do is to cat `/secret_cake_recipe/`, but the file is only readable by an admin(1338) while we are user(1337).
To gain higher privileges we need to exploit holey_beep application which is again setuid binary.

We got holey_beep binary in the attachment, so we don't have to dump it manually (for the first time I didn't realize it).
We can check that the application is 64bit ELF with PIE and NX enabled and it's not stripped.

Unfortunately LD_PRELOAD trick won't work again, because it's setuid binary (it is described here https://stackoverflow.com/questions/18058426/does-using-linux-capabilities-disables-ld-preload#18086884), so we have to find real vulnerability.

Let's analyze the code then. First it adds signal handler for SIGTERM (`kill -l` shows list of signals, but we could guess it also based on handler name which is `handle_sigterm`).
If we pass any arguments it opens `dev/console` (not `/dev/console`) moves the handler to `cs:device` register. Then it convert nth parameter to int with atoi and calls ioctl(cs:device,4B2Fh,our_input).
If an error occurs it prints proper message and later (in both cases) it closes the device and increments counter. The proccess repeats for each parameter and after it the application exits.

Our handler checks if `cs:device` is set, than calls ioctl(cs:device,4B2Fh,0) and if it fails (the result will be negative) it prints the error, reads 1023 bytes from the the file/device and prints them.

I created simple test.c file to see how ioctl works with files.
```c
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
int main(){
	int fd = open("test.txt",0);
	printf("%d",ioctl(fd,0x4B2F,0));
	return 0;
}
```
And it printed `-1` (so exactly what we want)! It means that we can create dev/console in any directory, run the program from there and it will open our file. We cannot create files in our home directory, but /tmp is writeable.
We can create symlink to our flag (`cp` and hardlinks won't work) there.
```
/bin/sh
cd /tmp
mkdir dev
ln -s /secret_cake_recipe dev/console
(/home/user/holey_beep $(echo {1..10000}) &);jobs -p
```
Unfortunately it didn't work. The program executed too fast and jobs -p returns nothing.
I spent a lot of time looking for something useful in the Internet and I found this https://linux.die.net/man/7/pipe
It says that "If the pipe is full, then a write(2) will block or fail" and it also says that the pipe capacity is 65536 bytes (in modern versions of linux).
So we have to force the application to print more than 65536 bytes, pipe its standard error to anything that will give us enough time to execute `jobs -p` (or equivalent) and then send SIGERM.
 
Unfortunately it still didn't work... after many attempts it appeared that I had to change $(echo {1..10000}) to $(seq 1 10000), I also changed `jobs -p` to `pidof`
```
/home/user/holey_beep $(seq 1 10000) 2>&1 | ( sleep 3;cat - )&
kill -15 `pidof /home/user/holey_beep`
```

[exploit](exploit.py)

Flag: `CTF{the_cake_wasnt_a_lie}`
