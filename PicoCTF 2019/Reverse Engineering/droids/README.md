# droids0

Run [the app](zero.apk) in android studio, click the button and check `logcat` output.

Flag: `picoCTF{a.moose.once.bit.my.sister}`

# droids1

Use [this website](http://www.javadecompilers.com/apk/) to decompile the app.

In [resources/res/values/strings.xml](strings1.xml) you can find the password - `opossum`.

Flag: `picoCTF{pining.for.the.fjords}`

# droids2

Use [this website](http://www.javadecompilers.com/apk/) to decompile the app.

In [sources\com\hellocmu\picoctf\FlagstaffHill.java](source2.java) you can find the function that validates the password.

Password: `dismass.ogg.weatherwax.aching.nitt.garlick`

Flag: `picoCTF{what.is.your.favourite.colour}`

# droids3

Use [this website](http://www.javadecompilers.com/apk/) to decompile the app.

In [sources\com\hellocmu\picoctf\FlagstaffHill.java](source3.java) there are 3 functions `nope`, `yep` and `getFlag`. We can see that `getFlag` calls `nope` and `yep` is never called. `yep` function most likely returns our flag.

With [apktool](https://ibotpeaches.github.io/Apktool/) we can modify and recompile the app.

First we have to decompile it again. Then we need to modify [smali/com/hellocmu/picoctf/FlagstaffHill.smali](smali3.smali) (in repository I included only modified version). We could change `getFlag` function to call `yep` instead of `nope`, but I found it easier to copy `yep` function body and paste it inside `nope` function.

Now you have to recompile the application with apktool and sign it with [uber apk signer](https://github.com/patrickfav/uber-apk-signer).

Finally you can run the application and get the flag.

Flag: `picoCTF{tis.but.a.scratch}`

# droids4

Use [this website](http://www.javadecompilers.com/apk/) to decompile the app.

In [sources\com\hellocmu\picoctf\FlagstaffHill.java](source4.java) you can find the function that validates the password.

Password: `alphabetsoup`

This time though it's not enough. The function that returns flag is never called. We have to patch the application to call `cardamom` function if the password matches.

We need to use apktool and uber apk signer again (look [droids3](#droids3)).

[Modified smali/com/hellocmu/picoctf/FlagstaffHill.smali](smali4.smali)

Flag: `picoCTF{not.particularly.silly}`