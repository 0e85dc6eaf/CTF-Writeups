#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>
#include <string.h>

#define NUM_ROOMS 10

typedef struct chat_message* chat_message_t;

struct chat_message {
    uint64_t uid;
    size_t length;
    char *text;
    chat_message_t prev;
};

chat_message_t rooms[NUM_ROOMS];

void *xmalloc(size_t bytes) {
    void *ret = malloc(bytes);
    if (!ret) {
        perror("xmalloc");
        exit(1);
    }
    return ret;
}

void *xrealloc(void *old, size_t bytes) {
    void *ret = realloc(old, bytes);
    if (!ret) {
        perror("xrealloc");
        exit(1);
    }
    return ret;
}

size_t normalize_size(size_t length) {
    return (length + 7) / 8 * 8;
}

void message_add_status(chat_message_t msg, char status) {
    msg->text[0] = status;
    msg->text[1] = '\t';
}

char message_status(chat_message_t msg) {
    return msg->text[0];
}

void update_message(chat_message_t msg, char *new_text) {
    size_t len = strlen(new_text) + 1;
    if (len > msg->length) {
        msg->text = xrealloc(msg->text, normalize_size(len));
    }
    strncpy(msg->text+2, new_text, len);
    message_add_status(msg, '*');
}

chat_message_t new_message(chat_message_t prev, uint64_t uid, size_t length) {
    chat_message_t msg = xmalloc(sizeof(struct chat_message));
    length = normalize_size(length);
    msg->text = xmalloc(length);
    msg->uid = uid;
    msg->length = length;
    msg->prev = prev;
    message_add_status(msg, ' ');

    return msg;
}

chat_message_t make_message(chat_message_t prev, uint64_t uid, char *text) {
    size_t length = strlen(text) + 1;
    chat_message_t msg = new_message(prev, uid, length+2);
    strncpy(msg->text+2, text, length);

    return msg;
}

void add_message_after(chat_message_t cur, uint64_t uid, char *text) {
    chat_message_t msg = make_message(cur->prev, cur->uid, text);
    char *new_text = msg->text;
    msg->text = cur->text;

    cur->text = new_text;
    cur->uid = uid;
    cur->prev = msg;
}

chat_message_t load_messages(chat_message_t orig, FILE *file) {
    char buf[1024];
    uint64_t uid;
    int nscan;
    chat_message_t cur = orig;
    while ((nscan = fscanf(file, "%" SCNu64 " %1024[^\n]", &uid, buf)) != -1) {
        if (nscan != 2) continue;
        cur = make_message(cur, uid, buf);
    }
    return cur;
}

chat_message_t find_message(chat_message_t chat, char *needle) {
    if (!chat || !needle) return NULL;
    if (strstr(chat->text, needle)) return chat;
    return find_message(chat->prev, needle);
}

void print_message(chat_message_t msg) {
    if (msg) {
        printf("%10" PRIu64 " %s\n", msg->uid, msg->text);
    }
}

void print_messages(chat_message_t chat, size_t limit) {
    if (!chat || !limit) return;
    print_messages(chat->prev, limit-1);
    print_message(chat);
}

void load_all_messages() {
    for (size_t room = 0; room < NUM_ROOMS; ++room) {
        char room_name[32];
        rooms[room] = NULL;
        snprintf(room_name, 32, "room.%zu.log", room);
        FILE *f = fopen(room_name, "r");
        if (f) {
            rooms[room] = load_messages(rooms[room], f);
            fclose(f);
        }
    }
}

bool ends_in_newline(char *buf) {
    return !!strchr(buf, '\n');
}

int readline(char *buf, size_t length) {
    printf("> ");
    char *result = fgets(buf, length, stdin);
    if (result != NULL && !ends_in_newline(buf) && !feof(stdin)) {
        do {
            result = fgets(buf, length, stdin);
        } while (result != NULL && !ends_in_newline(buf));
        printf("Line too long\n");
        return result == NULL ? -1 : 0;
    }
    if (result == NULL) {
        return -1;
    }
    char *newline = strchr(buf, '\n');
    if (newline != NULL) {
        *newline = '\0';
    }
    return strlen(result);
}

void print_commands() {
    printf(
        "Commands:\n"
        "\tchat <chatid>          print out a conversation\n"
        "\tfind <chatid> <str>    find a message\n"
        "\tedit <newtext>         edit the most recently found message\n"
        "\tadd  <uid> <text>      add a message after the most recently found message\n"
        "\tquit                   exit\n"
    );
}

void sh_loop() {
    char line[256];
    chat_message_t msg = NULL;
    int line_length;
    while ((line_length = readline(line, 256)) != -1) {
        if (line_length == 0) continue;
        char *command = strtok(line, " ");
        if (!strcmp(command, "quit")) {
            break;
        } else if (!strcmp(command, "help")) {
            print_commands();
        } else if (!strcmp(command, "chat")) {
            uint64_t id = strtoul(strtok(NULL, " "), NULL, 10);
            if (1 <= id && id <= NUM_ROOMS) {
                print_messages(rooms[id-1], 50);
            } else {
                printf("Invalid conversation id.\n");
            }
        } else if (!strcmp(command, "find")) {
            uint64_t id = strtoul(strtok(NULL, " "), NULL, 10);
            char *needle = strtok(NULL, "");
            if (1 <= id && id <= NUM_ROOMS) {
                msg = find_message(rooms[id-1], needle);
                print_message(msg);
            } else {
                printf("Invalid conversation id.\n");
            }
        } else if (!msg) {
            printf("You need to find a message first.\n");
        } else if (!strcmp(command, "add")) {
            uint64_t uid = strtoul(strtok(NULL, " "), NULL, 10);
            char *text = strtok(NULL, "");
            if (text) {
                add_message_after(msg, uid, text);
                printf("Message added.\n");
            } else {
                printf("Invalid message text.\n");
            }
        } else if (!strcmp(command, "edit")) {
            char *text = strtok(NULL, "");
            if (text) {
                update_message(msg, text);
                printf("Message edited.\n");
            } else {
                printf("Invalid message text.\n");
            }
        }
    }
}

int main(int argc, char **argv) {
    setbuf(stdout, NULL);
    load_all_messages();
    printf("Welcome to the chat logs.\nType \"help\" for a command listing.\n");
    sh_loop();
}
