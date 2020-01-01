#include <stdio.h>
extern int asm0(int,int);
int main(){
	printf("Flag: 0x%x\n",asm0(0x2a,0x4f));
	return 0;
}