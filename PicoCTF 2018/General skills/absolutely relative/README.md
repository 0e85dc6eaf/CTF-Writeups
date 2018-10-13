# absolutely relative

> In a filesystem, everything is relative ¯\_(ツ)_/¯. Can you find a way to get a flag from this program? You can find it in /problems/absolutely-relative_1_15eb86fcf5d05ec169cc417d24e02c87 on the shell server. Source. 

Hints:

> Do you have to run the program in the same directory? (⊙.☉)7

> Ever used a text editor? Check out the program 'nano'

This one is also a copy of a challenge from picoCTF2017.

Basically this line
```c
file = fopen( "./permission.txt" , "r");
```
will look for `permission.txt` file in the directory you are currently in, not where the binary is located.
To exploit it, create a file named `permission.txt` in your home directory and run the application like this
```
you@pico-2018-shell-1:~$ /problems/absolutely-relative_1_15eb86fcf5d05ec169cc417d24e02c87/absolutely-relative
You have the write permissions.
picoCTF{3v3r1ng_1$_r3l3t1v3_a97be50e}
```

Flag is `picoCTF{3v3r1ng_1$_r3l3t1v3_a97be50e}`.