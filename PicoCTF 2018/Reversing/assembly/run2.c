#include <stdio.h>
extern int asm2(int,int);
int main(){
	printf("Flag: 0x%x\n",asm2(0x6,0x28));
	return 0;
}