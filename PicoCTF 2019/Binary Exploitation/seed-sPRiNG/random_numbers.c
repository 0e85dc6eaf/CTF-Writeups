#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main(){
	srand(time(0));
	for(int i=0;i<32;++i)
	{
		printf("%d\n",(rand()%16));
	}
	return 0;
}