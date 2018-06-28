# Moar

> https://ctftime.org/writeup/10290

When we netcat to the server we can see `man socat` output only. But `man` allows us to execute commands. All we need to do is to type `!command`.
Running `!ls -la /home/moar` reveals some secret file `disable_dmz.sh`. Let's cat it.
```
#!/bin/sh
echo 'Disabling DMZ using password CTF{SOmething-CATastr0phic}'
echo CTF{SOmething-CATastr0phic} > /dev/dmz
```

Flag: `CTF{SOmething-CATastr0phic}`