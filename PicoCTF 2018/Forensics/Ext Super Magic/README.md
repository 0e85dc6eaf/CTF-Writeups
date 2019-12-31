# Ext Super Magic

Two bytes at offset 1080 in [ext-super-magic.img](ext-super-magic.img) are corrupted. You must replace them with `\x53\xef`.

[script](fix.py)

[fixed image](fixed.img)

Now you can open image file in 7-zip and extract [flag.jpg](flag.jpg).

Flag: `picoCTF{a7DB29eCf7dB9960f0A19Fdde9d00Af0}`
