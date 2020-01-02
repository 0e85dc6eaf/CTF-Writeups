#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

#define MAX_SWORD_NUM			6
#define READ_INT_BUF_LEN		32
#define MAX_SWORD_LEN			0x100
#define FORGE_TIME			2
#define ALARM_TIME			30

struct sword_s {
	int name_len;
	int weight;
	
	char *sword_name;
	void (*use_sword)(char *ptr);
	int is_hardened;
};

struct sword_list_s {
	int is_used;
	struct sword_s *sword;
};

struct sword_list_s sword_lists[MAX_SWORD_NUM];

void show_menu() {
	printf("/* Welcome! */\n"
		   "1. Forge a sword.\n"
		   "2. Synthesise two sword.\n"
		   "3. Show a sword.\n"
		   "4. Destroy a sword.\n"
		   "5. Harden a sword.\n"
		   "6. Equip a sword.\n"
		   "7. Quit.\n");
}

void free_sword() {
	int slot;
	printf("What's the index of the sword?\n");
	slot = get_int();
	if (slot < 0 || slot >= MAX_SWORD_NUM ||
		!sword_lists[slot].is_used) {
		printf("I don't trust your number!!!!\n");
		exit(-1);
	}

	sword_lists[slot].is_used = 0;
	char *name = sword_lists[slot].sword->sword_name;

	free(sword_lists[slot].sword);
	free(name);
}

int get_int(void) {
	char str[READ_INT_BUF_LEN];
	char ch;
	int i;

	for (i = 0; (read(STDIN_FILENO, &ch, 1), ch) != '\n' &&
		i < READ_INT_BUF_LEN - 1 && ch != -1; i++) {
		str[i] = ch;
	}
	str[i] = '\x00';
	return atoi(str);
}

int pick_sword_free_slot() {
	for (int i = 0; i < MAX_SWORD_NUM; i++) {
		if (!sword_lists[i].is_used) {
			return i;
		}
	}

	return -1;
}

void show_sword() {
	int slot;
	printf("What's the index of the sword?\n");
	slot = get_int();
	if (slot < 0 || slot >= MAX_SWORD_NUM ||
		!sword_lists[slot].is_used) {
		printf("I don't trust your number!!!!\n");
		exit(-1);
	}

	if (sword_lists[slot].is_used == 0) {
		printf("Haha!!! There is a hacker!!\n");
		exit(-1);
	}

	printf("The weight is %u\n",
		(unsigned int)sword_lists[slot].sword->weight);
	printf("The name is %s\n", sword_lists[slot].sword->sword_name);
}

void hoo(char *name) {
	printf("I use sword %s..... It's so cooool!\n", name);
}

void harden_sword() {
	int slot;
	printf("What's the index of the sword?\n");
	slot = get_int();
	if (slot < 0 || slot >= MAX_SWORD_NUM ||
		!sword_lists[slot].is_used) {
		printf("I don't trust your number!!!!\n");
		exit(-1);
	}

	if (sword_lists[slot].sword->is_hardened) {
		printf("This sword is already hardened!\n");
		return;
	}

	printf("What's the length of the sword name?\n");
	
	/* Get name_len. */
	int len = get_int();
	if (len < 0) {
		printf("Oh no there is a hacker!!!!\n");
		exit(-1);
	}

	if (len > MAX_SWORD_LEN) {
		printf("The name is too long.\n");
		free(sword_lists[slot].sword);
		return;
	}

	sword_lists[slot].sword->name_len = len;

	/* Get sword name. */
	sword_lists[slot].sword->sword_name = malloc(len + 1);

	if (!sword_lists[slot].sword->sword_name) {
	        puts("malloc() returned NULL. Out of Memory\n");
		exit(-1);
	}
	
	printf("Plz input the sword name.\n");

	char ch;
	int i;
	for (i = 0; (read(STDIN_FILENO, &ch, 1), ch) != '\n' &&
		i < len && ch != -1; i++) {
		sword_lists[slot].sword->sword_name[i] = ch;
	}
	sword_lists[slot].sword->sword_name[i] = '\x00';

	/* Get sword weight. */
	printf("What's the weight of the sword?\n");
	int weight = get_int();
	
	printf("OK....Plz wait for forging the sword..........\n");
	sleep((weight + 1) * 10000000);

	sword_lists[slot].sword->weight = weight;
	sword_lists[slot].sword->use_sword = hoo;
	sword_lists[slot].sword->is_hardened = 1;
}

void equip_sword() {
	int slot;
	printf("What's the index of the sword?\n");
	slot = get_int();
	if (slot < 0 || slot >= MAX_SWORD_NUM ||
		!sword_lists[slot].sword) {
		printf("I don't trust your number!!!!\n");
		exit(-1);
	}

	/* Apparently there should be system('/bin/sh'). */
	(sword_lists[slot].sword->use_sword)(sword_lists[slot].sword->sword_name);
}

/* Vuln. */
void synthe_sword() {
	int slot_1, slot_2;
	printf("What's the index of the first sword?\n");
	slot_1 = get_int();
	if (slot_1 < 0 || slot_1 >= MAX_SWORD_NUM ||
		!sword_lists[slot_1].is_used) {
		printf("I don't trust your number!!!!\n");
		exit(-1);
	}

	printf("What's the index of the second sword?\n");
	slot_2 = get_int();
	if (slot_2 < 0 || slot_2 >= MAX_SWORD_NUM ||
		!sword_lists[slot_2].is_used) {
		printf("I don't trust your number!!!!\n");
		exit(-1);
	}

	printf("OK.... Forge two swords now!!\n");
	struct sword_list_s sword1_list = sword_lists[slot_1];
	struct sword_list_s sword2_list = sword_lists[slot_2];

	/* Two swords are lost. */
	sword1_list.is_used = sword2_list.is_used = 0;

	sleep(FORGE_TIME);

	/* Combinne two names together. */
	sword2_list.sword->sword_name = realloc(sword2_list.sword->sword_name,
		sword1_list.sword->name_len + sword2_list.sword->name_len + 1);
	if (!sword2_list.sword->sword_name) {
		exit(-1);
	}

	memcpy(sword2_list.sword->sword_name + sword2_list.sword->name_len,
		sword1_list.sword->sword_name, sword1_list.sword->name_len);

	sword2_list.sword->name_len += sword1_list.sword->name_len;
	
	/* New sword is created. */
	sword2_list.is_used = 1;

	/* Clear the first sword. */
	free(sword1_list.sword->sword_name);

	printf("YOu have the NEW sword!\n");
}

void create_sword() {
	int slot = pick_sword_free_slot();
	if (slot == -1) {
		printf("Oh my! There are no slot for new swords!\n");
		return;
	}

	sword_lists[slot].sword = malloc(sizeof(struct sword_s));
	if (!sword_lists[slot].sword) {
	        puts("malloc() returned NULL. Out of Memory\n");
		exit(-1);
	}

	sword_lists[slot].is_used = 1;
	sword_lists[slot].sword->is_hardened = 0;
	printf("New sword is forged ^_^. sword index is %d.\n", slot);
}

void alarm_handler(int sig) {
	printf("Blade master is angry!\n");
	exit(-1);
}

int main() {


        setvbuf(stdout, NULL, _IONBF, 0);
  
	/* If someone can print some ascii art, that should be better. */
	
	signal(SIGALRM, alarm_handler);
	alarm(ALARM_TIME);

	char buf[READ_INT_BUF_LEN];
	while (1) {
		show_menu();

		if (read(STDIN_FILENO, buf, READ_INT_BUF_LEN) == 0) {
			return -1;
		}

		int command = atoi(buf);
		switch (command) {
			case 1:
				create_sword();
				break;

			case 2:
				synthe_sword();
				break;

			case 3:
				show_sword();
				break;

			case 4:
				free_sword();
				break;

			case 5:
				harden_sword();
				break;

			case 6:
				equip_sword();
				break;

			case 7:
				printf("Thank you!\n");
				break;

			default:
				break;
		}
	}
}
