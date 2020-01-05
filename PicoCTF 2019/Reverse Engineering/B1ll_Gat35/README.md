# B1ll_Gat35

Flag doesn't seem to depend on input, so we can solve this challenge easy way and just patch the condition in `main` function.

[patched application](win-exec-1.exe)

[original application](win-exec-1.exe.bak)

(you can input anything except for the correct key)
```
>win-exec-1.exe
Input a number between 1 and 5 digits: 1
Initializing...
Enter the correct key to get the access codes: 1
Correct input. Printing flag: PICOCTF{These are the access codes to the vault: 1063340}
```

Flag: `PICOCTF{These are the access codes to the vault: 1063340}`