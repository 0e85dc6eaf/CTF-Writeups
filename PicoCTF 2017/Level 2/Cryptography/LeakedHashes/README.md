# LeakedHashes

> Someone got hacked! Check out some service's password hashes that were leaked at hashdump.txt! Do you think they chose strong passwords? We should check... The service is running at shell2017.picoctf.com:44804!

Hints:

> See if you can crack any of the login credentials and then connect to the service as one of the users. What's the chance these hashes have actually already been broken by someone else? Are there websites that host those cracked hashes? Connect from the shell with nc.

We can use [this website](https://hashkiller.co.uk/md5-decrypter.aspx) to 'decrypt' our hashes.

[cracked passwords](cracked.txt)

We can see that we cracked all of them apart from root password. So let's try to login.

```
>ncat shell2017.picoctf.com 44804
enter username:
christene
christene's password:r3ckr3ck
welcome to shady file server. would you like to access the cat ascii art database? y/n
y

     /\_/\
    ( o o )
  G-==_Y_==-M
      `-'

  /\ /\
  (O o)
=(: ^ :)=
  '*v*'

 |\_/|
 (. .)
  =w= (\
 / ^ \//
(|| ||)
,""_""_ .

     /\_/\
    ( o o )
   -==_Y_==-
      `-'
    /\**/\
   ( o_o  )_)
   ,(u  u  ,),
  {}{}{}{}{}{}

  /\_/\
 ( o.o )
  > ^ <

       /\_/\
  /\  / o o \
 //\ \~(*)~/
 `  \/   ^ /
    | \|| ||
    \ '|| ||
     \)()-())

   A_A
  (-.-)
   |-|
  /   \
 |     |  __
 |  || | |  \___
 \_||_/_/

     /\__/\
    /`    '\
  === 0  0 ===
    \  --  /    - flag is 3977df525282eaf0e99f86efd2b645ed

   /        \
  /          \
 |            |
  \  ||  ||  /
   \_oo__oo_/#######o

  /\___/\
 ( o   o )
 (  =^=  )
 (        )
 (         )
 (          )))))))))))

 /\ /\
 (O o)
=(:^:)=
   U

    _,,/|
    \o o'
    =_~_=
    /   \ (\
   (////_)//
   ~~~

   /\     /\
  {  `---'  }
  {  O   O  }
~~|~   V   ~|~~
   \  \|/  /
    `-----'__
    /     \  `^\_
   {       }\ |\_\_   W
   |  \_/  |/ /  \_\_( )
    \__/  /(_E     \__/
      (  /
       MM

              ("`-''-/").___..--''"`-._
               `6_ 6  )   `-.  (     ).`-.__.`)
               (_Y_.)'  ._   )  `._ `. ``-..-'
             _..`--'_..-_/  /--'_.' ,'
           (il),-''  (li),'  ((!.-'

from http://user.xmission.com/~emailbox/ascii_cats.htm
```

The flag is `3977df525282eaf0e99f86efd2b645ed`.