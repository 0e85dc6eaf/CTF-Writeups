#include <stdio.h>
extern int asm1(int);
int main(){
	printf("Flag: 0x%x\n",asm1(0x15e));
	return 0;
}