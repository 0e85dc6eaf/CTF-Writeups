#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

FILE *log_file;

void append_command(char type, char *data) {
    fprintf(log_file, "%c %s\n", type, data);
}

void set_login_message(char *message) {
    if (!message) {
        printf("No message chosen\n");
        exit(1);
    }
    printf("Login message set!\n%s\n", message);

    append_command('l', message);
    exit(0);
}

void set_exit_message(char *message) {
    if (!message) {
        printf("No message chosen\n");
        exit(1);
    }
    printf("Exit message set!\n");
    printf(message);

    append_command('e', message);
    exit(0);
}

void set_prompt(char *prompt) {
    if (!prompt) {
        printf("No prompt chosen\n");
        exit(1);
    }
    if (strlen(prompt) > 10) {
        printf("Prompt too long\n");
        exit(1);
    }
    printf("Login prompt set to: %10s\n", prompt);

    append_command('p', prompt);
    exit(0);
}

void print_help() {
    printf(
        "You can:\n"
        "    login <login-message>    set the login message\n"
        "    exit <exit-message>      set the exit message\n"
        "    prompt <prompt>          set the command prompt\n"
    );
}

void loop() {
    char buf[1024];
    while (true) {
        printf("Config action: ");
        char *result = fgets(buf, 1024, stdin);
        if (!result) exit(1);
        char *type = strtok(result, " ");
        if (type == NULL) {
            continue;
        }
        char *arg = strtok(NULL, "\n");
        switch (type[0]) {
        case 'l':
            set_login_message(arg);
            break;
        case 'e':
            set_exit_message(arg);
            break;
        case 'p':
            set_prompt(arg);
            break;
        default:
            printf("Command unrecognized.\n");
            /* Fallthrough */
        case 'h':
            print_help();
            break;
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Requires log file\n");
        return 1;
    }
    log_file = fopen(argv[1], "a");
    
    setbuf(stdout, NULL);
    loop();
    return 0;
}
