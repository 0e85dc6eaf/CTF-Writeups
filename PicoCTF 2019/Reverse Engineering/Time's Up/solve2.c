#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdbool.h>
#define DATA_START 11
struct Op{
	int type;
	long long int value;
};
int getLength(long long int number)
{
	if(number==0)
	{
		return 1;
	}
	int count = (number < 0);
	while(number!=0)
	{
		count++;
		number/=10;
	}
	return count;
}
int main()
{
	pid_t pid;
	int fd1[2];
	int fd2[2];
	struct Op opOut[100];
	struct Op opStack[100];
	long long int opValueStack[100];
	pipe(fd1);
	pipe(fd2);
	pid = fork();
	if(pid==0)
	{
		close(fd1[1]);
        close(fd2[0]);
		dup2(fd1[0], STDIN_FILENO);
		dup2(fd2[1], STDOUT_FILENO);
		execv("./times-up-again",(char *[]){ "./times-up-again",NULL });
	}
	else
	{
		close(fd1[0]);
        close(fd2[1]);
		int status;
		char buf1[1000];
		int rv1 = read(fd2[0],buf1,(size_t)1000);
		buf1[rv1]=0;
		int outId = -1;
		int stackId = -1;
		for(int i=DATA_START;i<rv1;++i)
		{
			if(buf1[i]=='\n'){
				break;
			}
			switch(buf1[i])
			{
				case ' ':
				{
					break;
				}
				case '+':
				case '-':
				case '*':
				case '/':
				{
					opStack[++stackId] = (struct Op){.type=1,.value=buf1[i]};
					break;
				}
				case '(':
				{
					if( (buf1[i+1]>='0' && buf1[i+1]<='9') || buf1[i+1] == '-')
					{
						long long int val;
						sscanf((char*)(buf1+i+1),"%lld",&val);
						i+=getLength(val);
						i++;
						opOut[++outId] = (struct Op){.type=0,.value=val};
					}
					else
					{
						opStack[++stackId] = (struct Op){.type=1,.value=buf1[i]};
					}
					break;
				}
				case ')':
				{
					while(stackId>=0)
					{
						if(opStack[stackId].value != '(')
						{
							opOut[++outId] = opStack[stackId--];
						}
						else
						{
							stackId--;
							break;
						}
					}
					break;
				}
				default:
				{
					printf("[ERROR] Unexpected character %d\n",buf1[i]);
					exit(1);
				}
			}
		}
		while(stackId>=0)
		{
			opOut[++outId] = opStack[stackId--];
		}
		int valStackId = -1;
		for(int i=0;i<=outId;++i)
		{
			if(opOut[i].type==0)
			{
				opValueStack[++valStackId] = opOut[i].value;
			}
			else
			{
				long long int a = opValueStack[valStackId--];
				long long int b = opValueStack[valStackId--];
				long long int result = 0;
				switch(opOut[i].value)
				{
					case '+':
					{
						result = b+a;
						break;
					}
					case '-':
					{
						result = b-a;
						break;
					}
					case '*':
					{
						result = b*a;
						break;
					}
					case '/':
					{
						result = b/a;
						break;
					}
					default:
					{
						printf("[ERROR] Undefined operation\n");
						exit(1);
					}
				}
				opValueStack[++valStackId] = result;
			}
		}
		if(valStackId==0)
		{
			char response[25];
			int count = sprintf(response,"%lld",opValueStack[0]);
			write(fd1[1],response,count+1);
		}
		else
		{
			printf("[ERROR] Something went wrong\n");
			exit(1);
		}
		char buf2[1000];
		int rv2 = read(fd2[0],buf2,(size_t)1000);
		buf2[rv2] = 0;
		printf("%s",buf2);
		close(fd1[1]);
		close(fd2[0]);
		waitpid(pid, &status, 0);
	}
	return 0;
}