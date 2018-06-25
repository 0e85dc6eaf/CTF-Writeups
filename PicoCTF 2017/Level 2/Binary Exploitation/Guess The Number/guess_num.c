/* How well do you know your numbers? */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void win(void) {
    printf("Congratulations! Have a shell:\n");
    system("/bin/sh -i");
}

int main(int argc, char **argv) {
    uintptr_t val;
    char buf[32] = "";

    /* Turn off buffering so we can see output right away */
    setbuf(stdout, NULL);

    printf("Welcome to the number guessing game!\n");
    printf("I'm thinking of a number. Can you guess it?\n");
    printf("Guess right and you get a shell!\n");

    printf("Enter your number: ");
    scanf("%32s", buf);
    val = strtol(buf, NULL, 10);

    printf("You entered %d. Let's see if it was right...\n", val);

    val >>= 4;
    ((void (*)(void))val)();
}
