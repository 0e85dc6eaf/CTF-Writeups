# Little School Bus

> Can you help me find the data in this littleschoolbus.bmp?

Hints:

> Look at least significant bit encoding!!

In this challenge we have to extract data hidden in the image using LSB method. However first we need to get rid of the BMP headers. One way we can do this is to convert image to raw (*.raw) format using IrfanView.
We must remember to check Flip image vertically and BGR color encoding as the BMP stores data in that manner. When we already have plain image data we can read LSB from it.
Let's write simple JS script which does it for us. The flag is in the beginning of result.

[script](index.js)

[result](result.txt)

The flag is `flag{remember_kids_protect_your_headers_f5e8}`.