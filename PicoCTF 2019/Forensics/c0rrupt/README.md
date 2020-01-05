# c0rrupt

When we open [the file](mystery) in hex editor, we can see that it's PNG file (magic is broken, but we have `sRGB`,`gAMA`,`pHYs` chunks).

First, we have to fix the magic. [fixed magic version](mystery1.png)

Then we can run `pngcheck` tool to see if there are any other problems with the file.

```
$ pngcheck mystery1.png
mystery1.png:  invalid chunk name "C"DR" (43 22 44 52)
ERROR: mystery1.png
```

Of course first chunk must be `IHDR` not `C"HR`, so we must fix it next. [next version](mystery2.png)

```
$ pngcheck mystery2.png
mystery2.png  CRC error in chunk pHYs (computed 38d82c82, expected 495224f0)
ERROR: mystery2.png
```

`pHYs` chunk CRC is invalid, fortunately the tool immediately computed the correct one for us, so we can simply replace the bytes. [next version](mystery3.png)

```
$ pngcheck mystery3.png
mystery3.png  invalid chunk length (too large)
ERROR: mystery3.png
```

The next chunk is probably `IDAT` not `\xabDET`. It also has invalid length.
We have to compute the correct one (0xffa5 - [script](calc_len.py)) and fix the file.

[final image](mystery4.png)

Flag: `picoCTF{c0rrupt10n_1847995}`