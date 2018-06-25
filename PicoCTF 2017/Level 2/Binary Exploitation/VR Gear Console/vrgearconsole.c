#include <stdlib.h>
#include <stdio.h>

int login() {
    int accessLevel = 0xff;
    char username[16];
    char password[32];
    printf("Username (max 15 characters): ");
    gets(username);
    printf("Password (max 31 characters): ");
    gets(password);

    if (!strcmp(username, "admin") && !strcmp(password, "{{ create_long_password() }}")) {
        accessLevel = 2;
    } else if (!strcmp(username, "root") && !strcmp(password, "{{ create_long_password() }}")) {
        accessLevel = 0;
    } else if (!strcmp(username, "artist") && !strcmp(password, "my-password-is-secret")) {
        accessLevel = 0x80;
    }

    return accessLevel;
}

int main(int argc, char **argv) {
    setbuf(stdout, NULL);
    printf(
        "+----------------------------------------+\n"
        "|                                        |\n"
        "|                                        |\n"
        "|                                        |\n"
        "|                                        |\n"
        "|  Welcome to the VR gear admin console  |\n"
        "|                                        |\n"
        "|                                        |\n"
        "|                                        |\n"
        "|                                        |\n"
        "+----------------------------------------+\n"
        "|                                        |\n"
        "|      Your account is not recognized    |\n"
        "|                                        |\n"
        "+----------------------------------------+\n"
        "\n\n\n\n"
        "Please login to continue...\n\n\n"
    );
    int access = login();

    printf("Your access level is: 0x%08x\n", access);

    if (access >= 0xff || access <= 0) {
        printf("Login unsuccessful.\n");
        exit(10);
    } else if (access < 0x30) {
        printf("Admin access granted!\n");
        printf("The flag is in \"flag.txt\".\n");
        system("/bin/sh");
    } else {
        printf("Login successful.\n");
        printf("You do not have permission to access this resource.\n");
        exit(1);
    }
}
