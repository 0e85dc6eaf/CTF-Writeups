# m00nwalk

You can use [this tool](https://github.com/colaclanth/sstv) to solve this challenge.

```
$ sstv -d message1.wav -o flag1.png
```

Flag: `picoCTF{beep_boop_im_in_space}`

# m00nwalk2

First decode all clues using the tool from previous challenge.

```
$ sstv -d clue1.wav -o clue1.png
$ sstv -d clue2.wav -o clue2.png
$ sstv -d clue3.wav -o clue3.png
```

Then use [this website](https://futureboy.us/stegano/decinput.html) to decode [message2.wav](message2.wav).

Password: `hidden_stegosaurus`

Flag: `picoCTF{the_answer_lies_hidden_in_plain_sight}`