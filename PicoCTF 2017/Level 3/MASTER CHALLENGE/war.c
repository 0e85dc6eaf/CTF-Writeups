#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NAMEBUFFLEN 32
#define BETBUFFLEN 8

typedef struct _card{
    char suit;
    char value;
} card;

typedef struct _deck{
    size_t deckSize;
    size_t top;
    card cards[52];
} deck;

typedef struct _player{
    int money;
    deck playerCards;
} player;

typedef struct _gameState{
  int playerMoney;
  player ctfer;
  char name[NAMEBUFFLEN];
  size_t deckSize;
  player opponent;
} gameState;

gameState gameData;

//Shuffles the deck
//Make sure to call srand() before!
void shuffle(deck * inputDeck){
    card temp;
    size_t indexA, indexB;
    size_t deckSize = inputDeck->deckSize;
    for(unsigned int i=0; i < 1000; i++){
        indexA = rand() % deckSize;
        indexB = rand() % deckSize;
        temp = inputDeck->cards[indexA];
        inputDeck->cards[indexA] = inputDeck->cards[indexB];
        inputDeck->cards[indexB] = temp;
    }
}

//Checks if a card is in invalid range
int checkInvalidCard(card * inputCard){
    if(inputCard->suit > 4 || inputCard->value > 14){
        return 1;
    }
    return 0;
}

//Reads input from user, and properly terminates the string
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

//Builds the deck for each player.
//Good luck trying to win ;)
void buildDecks(player * ctfer, player * opponent){
    for(size_t j = 0; j < 6; j++){
        for(size_t i = 0; i < 4; i++){
            ctfer->playerCards.cards[j*4 + i].suit = i;
            ctfer->playerCards.cards[j*4 + i].value = j+2;
        }
    }
    for(size_t j = 0; j < 6; j++){
        for(size_t i = 0; i < 4; i++){
            opponent->playerCards.cards[j*4 + i].suit = i;
            opponent->playerCards.cards[j*4 + i].value = j+9;
        }
    }
    ctfer->playerCards.cards[24].suit = 0;
    ctfer->playerCards.cards[24].value = 8;
    ctfer->playerCards.cards[25].suit = 1;
    ctfer->playerCards.cards[25].value = 8;
    opponent->playerCards.cards[24].suit = 2;
    opponent->playerCards.cards[24].value = 8;
    opponent->playerCards.cards[25].suit = 3;
    opponent->playerCards.cards[25].value = 8;

    ctfer->playerCards.deckSize = 26;
    ctfer->playerCards.top = 0;
    opponent->playerCards.deckSize = 26;
    opponent->playerCards.top = 0;
}

int main(int argc, char**argv){
    char betStr[BETBUFFLEN];
    card * oppCard;
    card * playCard;
    memset(&gameData, 0, sizeof(gameData));
    gameData.playerMoney = 100;
    int bet;

    buildDecks(&gameData.ctfer, &gameData.opponent);
    srand(time(NULL));//Not intended to be cryptographically strong

    shuffle(&gameData.ctfer.playerCards);
    shuffle(&gameData.opponent.playerCards);

    setbuf(stdout, NULL);

    //Set to be the smaller of the two decks.
    gameData.deckSize = gameData.ctfer.playerCards.deckSize > gameData.opponent.playerCards.deckSize
		 ? gameData.opponent.playerCards.deckSize : gameData.ctfer.playerCards.deckSize;

    printf("Welcome to the WAR card game simulator. Work in progress...\n");
    printf("Cards don't exchange hands after each round, but you should be able to win without that,right?\n");
    printf("Please enter your name: \n");
    memset(gameData.name,0,NAMEBUFFLEN);
    if(!readInput(gameData.name,NAMEBUFFLEN)){
        printf("Read error. Exiting.\n");
        exit(-1);
    }
    printf("Welcome %s\n", gameData.name);
    while(1){
        size_t playerIndex = gameData.ctfer.playerCards.top;
        size_t oppIndex = gameData.opponent.playerCards.top;
        oppCard = &gameData.opponent.playerCards.cards[oppIndex];
        playCard = &gameData.ctfer.playerCards.cards[playerIndex];
        printf("You have %d coins.\n", gameData.playerMoney);
        printf("How much would you like to bet?\n");
        memset(betStr,0,BETBUFFLEN);
        if(!readInput(betStr,BETBUFFLEN)){
            printf("Read error. Exiting.\n");
            exit(-1);
        };
        bet = atoi(betStr);
        printf("you bet %d.\n",bet);
        if(!bet){
            printf("Invalid bet\n");
            continue;
        }
        if(bet < 0){
            printf("No negative betting for you! What do you think this is, a ctf problem?\n");
           continue;
        }
        if(bet > gameData.playerMoney){
            printf("You don't have that much.\n");
            continue;
        }
        printf("The opponent has a %d of suit %d.\n", oppCard->value, oppCard->suit);
        printf("You have a %d of suit %d.\n", playCard->value, playCard->suit);
        if((playCard->value * 4 + playCard->suit) > (oppCard->value * 4 + playCard->suit)){
            printf("You won? Hmmm something must be wrong...\n");
            if(checkInvalidCard(playCard)){
                printf("Cheater. That's not actually a valid card.\n");
            }else{
                printf("You actually won! Nice job\n");           
                gameData.playerMoney += bet;
            }
        }else{
            printf("You lost! :(\n");
            gameData.playerMoney -= bet;
        }
        gameData.ctfer.playerCards.top++;
        gameData.opponent.playerCards.top++;
        if(gameData.playerMoney <= 0){
            printf("You are out of coins. Game over.\n");
            exit(0);
        }else if(gameData.playerMoney > 500){
            printf("You won the game! That's real impressive, seeing as the deck was rigged...\n");
	        system("/bin/sh -i");
            exit(0);
        }

        //TODO: Implement card switching hands. Cheap hack here for playability
        gameData.deckSize--;
        if(gameData.deckSize == 0){
            printf("All card used. Card switching will be implemented in v1.0, someday.\n");
            exit(0);
        }
        printf("\n");
	    fflush(stdout);
    };

    return 0;
}
