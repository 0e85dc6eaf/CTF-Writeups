# keyz

> While webshells are nice, it'd be nice to be able to login directly. To do so, please add your own public key to ~/.ssh/authorized_keys, using the webshell. Make sure to copy it correctly! The key is in the ssh banner, displayed when you login remotely with ssh, to shell2017.picoctf.com

Hints:

> There are plenty of tutorials out there. This one covers key generation: https://confluence.atlassian.com/bitbucketserver/creating-ssh-keys-776639788.html

> Then, use the web shell to copy/paste it, and use the appropriate tool to ssh to the server using your key

If we want to use PuTTY as our SSH client, we can generate the key using PuTTYgen. PuTTYgen provides clear GUI so I won't describe it step by step.
Once we've successfully generated the key, we can copy it to the clipboard and switch to the webshell.

```
<username>@shell-web:~$ mkdir .ssh 
<username>@shell-web:~$ echo "<HERE_PASTE_YOUR_KEY>" > .ssh/authorized_keys
```

When you login to the server you will see
```
Using username "<your_username>".
Authenticating with public key "<your_public_key>"
Congratulations on setting up SSH key authentication!
Here is your flag: who_needs_pwords_anyways
<your_username>@shell-web:~$
```

The flag is `who_needs_pwords_anyways`.


If you have troubles with it, have a look at [this tutorial](https://www.howtoforge.com/ssh_key_based_logins_putty). It describes step by step with screenshots what you have to do (pages 1-3).