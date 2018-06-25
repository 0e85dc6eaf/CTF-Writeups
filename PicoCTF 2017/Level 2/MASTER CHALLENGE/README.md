# Missing Identity

> Turns out, some of the files back from Master Challenge 1 were corrupted. Restore this one file and find the flag.

Hints:

> What file is this?

> What do you expect to find in the file structure?

> All characters in the file are lower case or numberical. There will not be any zeros.

When we open the file in notepad we can see it contains a lot of PNG files and what's more it ends with the list of files. It looks like an archive. When we change extension to zip, windows explorer shows us content of the archive, but we are not able to extract the flag.
First 6 bytes in the file are `XXXXXX` and from wikipedia we can find out that file headers in zip should begin with `Local file header signature` and `Version needed to extract`.
Replacing broken bytes in hex editor to `50 4b 03 04 14 00` allows us to extract flag from zip.

[Fixed zip](fixed.zip)

The flag is `zippidydooda29494995`.