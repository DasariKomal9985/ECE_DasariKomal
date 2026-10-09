#include<stdio.h>
#include<unistd.h>
int main()
{
	char *args[] = {"ls","-l",NULL};
	printf("Before execv\n");
	execv("/bin/ls",args);
	printf("execv failed\n");
	return 0;
}
