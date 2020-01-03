# 1_wanna_b3_a_r0ck5tar

Use [this website](https://codewithrockstar.com/online) to execute [lyrics.txt](lyrics.txt)

This time the application doesn't print anything. If we read [documentation](https://codewithrockstar.com/docs), we can learn that `listen` keyword reads line from standard input. There are 2 occurrences of `listen` in our app.

```
A guitar is a six-string
### irrelevant ###
Listen to the music
If the music is a guitar
```

Equivalent Python code:

```py
a_guitar = 10
music = input()
if int(music) == a_guitar:
	# do something
```

---

```
Music is a billboard-burning razzmatazz!
### irrelevant ###
Listen to the rhythm
If the rhythm without Music is nothing
```

Equivalent Python code:

```py
Music = 170
the_rhythm = input()
if int(the_rhythm) - Music == 0:
	# do something
```

---

Input:
```
10
170
```

Output:
```
Keep on rocking!
66
79
78
74
79
86
73
```

Convert to ASCII: [script](solve.py)

Flag: `picoCTF{BONJOVI}`