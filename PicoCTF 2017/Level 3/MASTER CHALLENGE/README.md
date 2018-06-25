# WAR

> Win a simple Card Game. Source. Connect on shell2017.picoctf.com:32251.

Hints:

> Bugs typically happen in groups. If you find one, what does it allow you to do?

This one was actually pretty easy (much easier than binary exploitation problems from this level). First, we need to notice the bug in readInput function.
```c
unsigned int readInput(char * buff, unsigned int len){
    size_t count = 0;
    char c;
    while((c = getchar()) != '\n' && c != EOF){
        if(count < (len-1)){
            buff[count] = c;
            count++;
        }
    }
    buff[count+1] = '\x00';
    return count;
}
```

The `count` variable is incremented in the loop, but null byte is added one byte later. If we provide input of maximum length, the null byte will be written just after the buffer in the memory

```c
typedef struct _gameState{
  int playerMoney;
  player ctfer;
  char name[NAMEBUFFLEN];
  size_t deckSize;
  player opponent;
} gameState;
```

If we overflow the name property, we can assign deckSize value. How can it be helpful?

```c
gameData.deckSize--;
if(gameData.deckSize == 0){
	printf("All card used. Card switching will be implemented in v1.0, someday.\n");
	exit(0);
}
```

Hmm... it means the deckSize will be -1 before it reaches the comparision. Thanks to it the gameplay will be much longer than 'author' expected. We can see only 26 cards are used. We are going to lose first 26 rounds, because of unfair cards assigning.
The next 26 round will be lost too, because the cards are uninitialized (and their values are 0) and if our card is equal the enemy's card, we lose.
```c
if((playCard->value * 4 + playCard->suit) > (oppCard->value * 4 + playCard->suit)){
```

Later in memory there's our name and we can use it to finally start winning the game. ASCII nickname will be invalid, but we can send `\x04` bytes to bypass it.
```c
int checkInvalidCard(card * inputCard){
    if(inputCard->suit > 4 || inputCard->value > 14){
        return 1;
    }
    return 0;
}
```

[Here's](main.js) the script solving the problem.
Example output of the script is very long, so i moved it to separate [file](output.txt)

The flag is `5f28113500ed744dea5b22743db9b9b6`.