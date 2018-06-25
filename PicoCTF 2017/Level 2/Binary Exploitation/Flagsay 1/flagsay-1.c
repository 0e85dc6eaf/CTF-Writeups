#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FIRSTCHAROFFSET 129
#define LINELENGTH 35
#define NEWLINEOFFSET 21
#define LINECOUNT 6

#define BUFFLEN 1024

char flag[] = "               _                                        \n"
	          "              //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~     \n"
	          "             //                                   /     \n"
	          "            //                                   /      \n"
	          "           //                                   /       \n"
	          "          //                                   /        \n"
	          "         //                                   /         \n"
	          "        //                                   /          \n"
	          "       //___________________________________/           \n"
	          "      //                                                \n"
	          "     //                                                 \n"
	          "    //                                                  \n"
	          "   //                                                   \n"
	          "  //                                                    \n"
	          " //                                                     \n";

char commandBase[] = "/bin/echo \"%s\"\n";

void placeInFlag(char * str){
	char * ptr = flag + FIRSTCHAROFFSET;
	char * lastInLine = ptr + LINELENGTH;
	size_t charRemaining = strlen(str);
	size_t linesDone = 0;
	while(charRemaining > 0 && linesDone < LINECOUNT){
		if(ptr == lastInLine){
			ptr += NEWLINEOFFSET;
			lastInLine += NEWLINEOFFSET + LINELENGTH;
			linesDone++;
			continue;
		}
		ptr[0] = str[0];
		ptr++;
		str++;
		charRemaining--;
	}
	
}



int main(int argc, char **argv){
	size_t flagSize = strlen(flag) + 1; //need to remember null terminator
	char * input = (char *)malloc(sizeof(char) * flagSize);
	input[flagSize-1] = '\x0';
	fgets(input, flagSize, stdin);
	char * temp = strchr(input, '\n');
	if(temp != NULL){
		temp[0] = '\x0';
	}
	placeInFlag(input);

	size_t commandLen = flagSize + strlen(commandBase) + 1;
	char * command = (char *)malloc(sizeof(char) * commandLen);
	snprintf(command, commandLen, commandBase, flag); 
	system(command);

	free(input);
	free(command);
}


