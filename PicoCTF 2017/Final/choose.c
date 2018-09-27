#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <alloca.h>

#define INPUTLEN 8
#define TEMPINPUTLEN 20
#define ENEMNAMELEN 12
#define NUMMONSTERS 11

#define ENEMSIZE sizeof(orc)

typedef struct _orc{
    char type;
    short damage;
    int health;
    char name[ENEMNAMELEN];
} orc;

typedef struct _goblin{
    char type;
    short damage;
    int health;
    char name[ENEMNAMELEN];
} goblin;

typedef struct _kobold{
    char type;
    short damage;
    int health;
    char name[ENEMNAMELEN];
} kobold;

typedef struct _unicorn{
    char type;
    int health;
    short damage;
    char name[ENEMNAMELEN];
} unicorn;

typedef struct _centaur{
    char type;
    int health;
    short damage;
    char name[ENEMNAMELEN];
} centaur;

typedef struct _troll{
    char type;
    short damage;
    int health;
    char name[ENEMNAMELEN];
} troll;

//This struct is the only unique one from the others
typedef struct _dragon{
    char type;
    short damage;
    long long health;
    char name[ENEMNAMELEN];
} dragon;

typedef struct _player{
    int health;
    short damage;
    short heal;
    short block;
    char wizardSight;
} player;

//Upper and lower case strings of all possible valid user inputs
char *commands = "ABHFabhf";
char *enemyTypes = "ogkuctOGKUCT";

//Strings for each of the possible winnings
char *winnings[] = {"Blocking sword","Improved Healing","Shield Stengthening", "Sword sharpening", "Healing Potion", "Wizard sight"};

dragon bigAndScary;
char inputStr[INPUTLEN];
player ctfer;
char enemyChain[NUMMONSTERS + 1];

//Reads input from user, and properly terminates the string
unsigned int readInput(char * buff, unsigned int len){
    size_t count = 0;
    char c;
    while((c = getchar()) != '\n' && !feof(stdin)){
        if(count < (len-1)){
            buff[count] = c;
            count++;
        }
    }
    buff[count] = '\x00';
    return count;
}

//Ease of use wrapper around read Input
void readWrapper(char * buff, unsigned int maxLen){
    memset(buff, 0, maxLen);
    if(!readInput(buff, maxLen)){
        printf("Read Error. Exiting\n");
        exit(EXIT_FAILURE);
    }
}

void buildOrc(orc * enemPtr){
    printf("Enter a name for this orc:\n");
    readWrapper(enemPtr->name, ENEMNAMELEN);
    enemPtr->type = 'o';
    enemPtr->health = 20;
    enemPtr->damage = 5; 
}

void buildGoblin(goblin * enemPtr){
    printf("Enter a name for this goblin:\n");
    readWrapper(enemPtr->name, ENEMNAMELEN);
    enemPtr->type = 'g';
    enemPtr->health = 20;
    enemPtr->damage = 5; 
}

void buildKobold(kobold * enemPtr){
    printf("Enter a name for this kobold:\n");
    readWrapper(enemPtr->name, ENEMNAMELEN);
    enemPtr->type = 'k';
    enemPtr->health = 20;
    enemPtr->damage = 5; 
}

void buildUnicorn(unicorn * enemPtr){
    printf("Enter a name for this unicorn:\n");
    readWrapper(enemPtr->name, ENEMNAMELEN);
    enemPtr->type = 'u';
    enemPtr->health = 20;
    enemPtr->damage = 5; 
}

void buildCentaur(centaur * enemPtr){
    printf("Enter a name for this centaur:\n");
    readWrapper(enemPtr->name, ENEMNAMELEN);
    enemPtr->type = 'c';
    enemPtr->health = 20;
    enemPtr->damage = 5; 
}

void buildTroll(troll * enemPtr){
    printf("Enter a name for this troll:\n");
    readWrapper(enemPtr->name, ENEMNAMELEN);
    enemPtr->type = 't';
    enemPtr->health = 20;
    enemPtr->damage = 5; 
}

void buildDragon(dragon * dragonPtr){
    memcpy(dragonPtr->name, "P0FF", 4);
    dragonPtr->type = 'd';
    dragonPtr->health = 0x1122334455667788;
    dragonPtr->damage = 35;
}

void printCommands(){
    printf("[A]: Attack\n");
    printf("[B]: Block\n");
    printf("[H]: Heal\n");
    printf("[F]: Flee\n");
}

void printPlayer(){
    printf("You have %d health, do %d damage, can block %d damage, and can heal %d damage\n", ctfer.health, ctfer.damage, ctfer.block, ctfer.heal);
}

void printDragon(){
    printf("%s Dragon has %lld health and does %d damage\n",bigAndScary.name, bigAndScary.health, bigAndScary.damage); 
}

void printEnemy(char * enemy){
    char type = enemy[0];
    orc * orcPtr;
    goblin * goblinPtr;
    kobold * koboldPtr;
    unicorn * unicornPtr;
    centaur * centaurPtr;
    troll * trollPtr;
    switch(type){
        case 'O':
        case 'o':
            orcPtr = (orc *)enemy;
            printf("Orc. Name %s Health %d Damage %d\n", orcPtr->name, orcPtr->health, orcPtr->damage);
            break;
        case 'G':
        case 'g':
            goblinPtr = (goblin *)enemy;
            printf("Goblin. Name %s Health %d Damage %d\n", goblinPtr->name, goblinPtr->health, goblinPtr->damage);
            break;
        case 'K':
        case 'k':
            koboldPtr = (kobold *)enemy;
            printf("Kobold. Name %s Health %d Damage %d\n", koboldPtr->name, koboldPtr->health, koboldPtr->damage);
            break;
        case 'U':
        case 'u':
            unicornPtr = (unicorn *)enemy;
            printf("Unicorn. Name %s Health %d Damage %d\n", unicornPtr->name, unicornPtr->health, unicornPtr->damage);
            break;
        case 'C':
        case 'c':
            centaurPtr = (centaur *)enemy;
            printf("Centaur. Name %s Health %d Damage %d\n", centaurPtr->name, centaurPtr->health, centaurPtr->damage);
            break;
        case 'T':
        case 't':
            trollPtr = (troll *)enemy;
            printf("Troll. Name %s Health %d Damage %d\n", trollPtr->name, trollPtr->health, trollPtr->damage);
            break;
        default:
            printf("Unknown enemy type\n");
            break;
    }
    if(ctfer.wizardSight){
        printf("Your sight shows the enemy at %p\n", enemy);
    }
}

void processWinnings(char type){
    switch(type){
        case 'O':
        case 'o':
            printf("You found %s\n", winnings[0]);
            ctfer.damage -= 5;
            ctfer.block += 5;
            break;
        case 'G':
        case 'g':
            printf("You found %s\n", winnings[1]);
            ctfer.heal += 5;
            break;
        case 'K':
        case 'k':
            printf("You found %s\n", winnings[2]);
            ctfer.block += 5;
            break;
        case 'U':
        case 'u':
            printf("You found %s\n", winnings[3]);
            ctfer.damage += 15;
            break;
        case 'C':
        case 'c':
            printf("You found %s\n", winnings[4]);
            ctfer.health += 50;
            break;
        case 'T':
        case 't':
            printf("You found %s\n", winnings[5]);
            ctfer.wizardSight = 1;
            break;
        default:
            break;
    }
}

//TODO: These are all the same size, so remove in future version for brevity
size_t getSize(char * enemy){
    char type = enemy[0];
    switch(type){
        case 'O':
        case 'o':
            return sizeof(orc);
        case 'G':
        case 'g':
            return sizeof(goblin);
        case 'K':
        case 'k':
            return sizeof(kobold);
        case 'U':
        case 'u':
            return sizeof(unicorn);
        case 'C':
        case 'c':
            return sizeof(centaur);
        case 'T':
        case 't':
            return sizeof(troll);
    }
    return 0;
}

void collectEnemData(char * enemies, char * enemyChain){
    unsigned int offset = 0;
    for(int i = 0; i < NUMMONSTERS; i++){
        char index = enemyChain[i];
        switch(index){
            case 'O':
            case 'o':
                buildOrc((orc *)(enemies + offset));
                offset += sizeof(orc);
                break;
            case 'G':
            case 'g':
                buildGoblin((goblin *)(enemies + offset));
                offset += sizeof(goblin);
                break;
            case 'K':
            case 'k':
                buildKobold((kobold *)(enemies + offset));
                offset += sizeof(kobold);
                break;
            case 'U':
            case 'u':
                buildUnicorn((unicorn *)(enemies + offset));
                offset += sizeof(unicorn);
                break;
            case 'C':
            case 'c':
                buildCentaur((centaur *)(enemies + offset));
                offset += sizeof(centaur);
                break;
            case 'T':
            case 't':
                buildTroll((troll *)(enemies + offset));
                offset += sizeof(troll);
                break;
        }

    }
}

int processCommand(char *inputStr, orc * tempEnemy){
    switch(inputStr[0]){
        case 'A':
        case 'a':
            printf("You deal %d damage.\n", ctfer.damage);
            printf("You are dealt %d damage.\n", tempEnemy->damage);
            ctfer.health -= tempEnemy->damage;
            tempEnemy->health -= ctfer.damage;
            break;
        case 'B':
        case 'b':
            printf("You block %d damage.\n", ctfer.block);
            short damage = tempEnemy->damage - ctfer.block;
            if(damage < 0){
                damage = 0;
            }
            printf("You are dealt %d damage.\n", damage);
            ctfer.health -= damage;
            break;
        case 'F':
        case 'f':
            printf("You try to flee. You got away safely.\n");
            return 1;
        case 'H':
        case 'h':
            printf("You heal %d damage.\n", ctfer.heal);
            printf("You are dealt %d damage.\n", tempEnemy->damage);
            ctfer.health += ctfer.heal;
            ctfer.health -= tempEnemy->damage; 
            break;
        default:
            printf("Invalid Entry\n");
            break;
    }
    return 0;
}

int processCommandDragon(char *inputStr){
    switch(inputStr[0]){
        case 'A':
        case 'a':
            printf("Your sword glances off the dragon's scales.\n");
            printf("You are dealt %d damage\n", bigAndScary.damage);
            ctfer.health -= bigAndScary.damage;
            break;
        case 'B':
        case 'b':
            printf("Your shield does nothing. Sorry. It's a dragon.\n");
            printf("You are dealt %d damage\n", bigAndScary.damage);
            ctfer.health -= bigAndScary.damage;
            break;
        case 'F':
        case 'f':
            printf("You try to flee. Dragons can fly, silly.\n");
            printf("You are dealt %d damage\n", bigAndScary.damage);
            ctfer.health -= bigAndScary.damage;
            break;
        case 'H':
        case 'h':
            printf("You heal %d damage. The dragon is better at eating you though than you are at healing.\n", ctfer.heal);
            printf("You are dealt %d damage\n", bigAndScary.damage);
            ctfer.health += ctfer.heal;
            ctfer.health -= bigAndScary.damage; 
            break;
        default:
            printf("Invalid Entry\n");
            break;
    }
    return 0; 
}

void runGame(){
    ctfer.health = 200;
    ctfer.damage = 10;
    ctfer.heal = 5;
    ctfer.block = 10;
    ctfer.wizardSight = 0;
    char enemies[ENEMSIZE * NUMMONSTERS];
    memset(enemies,0,ENEMSIZE*NUMMONSTERS);
    buildDragon(&bigAndScary);
    setbuf(stdout, NULL);
    printf("Welcome to the dungeon adventure simulator.\n");
    printf("You get the lovely job of being able to select which %d monsters you will face.\n", NUMMONSTERS);
    printf("These will be followed by a boss battle. I hope you're ready by then!\n\n");

    printf("What monsters would you like to face?\n");
    printf("Enter \'o\' for an orc\n");
    printf("\'g\' for a goblin\n");
    printf("\'k\' for a kobold\n");
    printf("\'u\' for a unicorn\n");
    printf("\'c\' for a centaur\n");
    printf("\'t\' for a troll\n");
    for(int i = 0; i < NUMMONSTERS; ){
        printf("%d: ",i);
        readWrapper(inputStr, INPUTLEN);
        if(!strchr(enemyTypes, inputStr[0]) || inputStr[0] == '\x00'){
            printf("Invalid enemy. Try again\n");
        }else{
            enemyChain[i] = inputStr[0];
            i++;
        }
    }
    enemyChain[NUMMONSTERS] = '\x00';
    collectEnemData(enemies, enemyChain);
    printf("You will fight:\n");
    size_t enemOffset = 0;
    for(int i = 0; i < NUMMONSTERS; i++){
        printEnemy(enemies + enemOffset);
        enemOffset += getSize((char *)(enemies + enemOffset));

    }
    enemOffset = 0;
    printf("Time to fight!\n");
    for(int i = 0; i < NUMMONSTERS; i++){
        //Can use an orc ptr as all the structs are the same size.
        orc * tempEnemy = (orc *)(enemies + enemOffset);
        while(1){
            printPlayer();
            printEnemy((char *)tempEnemy);
            printCommands();
            readWrapper(inputStr, INPUTLEN);
            if(!strchr(commands, inputStr[0]) || inputStr[0] == '\x00'){
                printf("Invalid command\n");
                continue;
            }
            if(processCommand(inputStr, tempEnemy)){
                break;
            }
            if(ctfer.health <= 0){
                printf("health %d\n", ctfer.health);
                printf("You are out of health. Game over\n");
                break;
            }
            if(tempEnemy->health <= 0){
                printf("You defeated this enemy. Best of luck with the next one.\n");
                processWinnings(((char *)tempEnemy)[0]);
                enemOffset += getSize((char *)tempEnemy);
                break;
            }                         
        }
    }
    printf("You beat all YOUR enemies. Time to fight MY enemy\n");
    while(1){
        printPlayer();
        printDragon();
        printCommands();
        readWrapper(inputStr, INPUTLEN);
        if(!strchr(commands, inputStr[0]) || inputStr[0] == '\x00'){
            printf("Invalid command\n");
            continue;
        }
        processCommandDragon(inputStr);
        if(ctfer.health <= 0){
            printf("You are out of health. Game over\n");
            break;
        }
        if(bigAndScary.health <= 0){
            printf("You defeated the dragon? NICE JOB!!\n");
            break;
        }
    }
}

int main(int argc, char**argv){
	runGame();
	return 1;
}
