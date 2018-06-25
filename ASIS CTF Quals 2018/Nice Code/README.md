# Nice Code

> Beautify php code! Here

> https://ctftime.org/writeup/9910

When we visit the website and follow the `Get started` link we can see the following message
```
substr($URL, -10) !== '/index.php'
```
When we change URI to `/admin/index.php` we get next message
```
$URL == '/admin/index.php'
```
I tried to bypass it with query string `/admin/index.php?q=index.php` , using double slash `//admin/index.php` and with `/admin/./index.php`, but it didn't work. Finally, i came up with the correct solution `/admin/index.php/index.php`. After visiting this URI I got link to second stage of this challenge [http://167.99.36.112:8080/another/index.php?source](http://167.99.36.112:8080/another/index.php?source). 

Server sends header `X-Powered-By: PHP/5.5.9-1ubuntu4.14` and I knew that array comparison in this PHP version is broken. Index is casted to 32bit integer, so `4294967296` will become `0`, but the problem occurs only in comparison, so b[0] will not equal "admin". Therefore the POST body can look like this
```
b[4294967296]=admin&b[1]=oloco
```
To get code execution we need to guess function name stored in `$k_Jk` and send it via GET. I thought about `call_user_func`, but it didn't work, so I used another PHP 'feature' that 0 equals non-numeric string when `==` is used. We also need to meet other requirements. Our code must be 3rd GET param and `x` param must be longer than 17 chars.
```
?x=17charslongstrings&useless=true&0=var_dump
```
This successfully dumps 0. We can see also that any parameter must be "equal" to function name, so we can send `0=something` instead of `useless=true`.

Unfortunately, there is one more problem. We can't use dots and spaces. Spaces can be replaced by horizontal tab - %09, but I have no idea how to deal with dots. For this reason I used `grep` to dump PHP sources. Unfortunately there wasn't anything interesting there, so the flag could be anywhere. I decided to run `grep -r "ASIS{" /`, but it's an ugly solution.
```
?x=17charslongstrings&0=var&grep%09-r%09&quot;ASIS{&quot;%09/=system
```
The nicer solution would be to `ls` the `/var` directory and notice `flag` file. Then we could just use `readfile`
```
?x=17charslongstrings&0=var&/var/flag=readfile
```

Anyway, it reveals the flag `ASIS{f52c5a0cf980887bdac6ccaebac0e8428bfb8b83}` as well as the filename `/var/flag`.