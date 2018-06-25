#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUF_LEN 64
char buffer[BUF_LEN];

int main(int argc, char** argv) {
    int fd = open("/dev/urandom", O_RDONLY);
    if(fd == -1){
        puts("Open error on /dev/urandom. Contact an admin\n");
        return -1;
    }
    int secret;
    if(read(fd, &secret, sizeof(int)) != sizeof(int)){
        puts("Read error. Contact admin!\n");
        return -1;
    }
    close(fd);
    printf("Give me something to say!\n");
    fflush(stdout);
    fgets(buffer, BUF_LEN, stdin);
    printf(buffer);

    int not_secret;
    printf("Now tell my secret in hex! Secret: ");
    fflush(stdout);
    scanf("%x", &not_secret);
    if(secret == not_secret){
        puts("Wow, you got it!");
        system("cat ./flag.txt");   
    }else{
        puts("As my friend says,\"You get nothing! You lose! Good day, Sir!\"");
    }

    return 0;
}
