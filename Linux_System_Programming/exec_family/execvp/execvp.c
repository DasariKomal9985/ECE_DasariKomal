#include<stdio.h>
#include<unistd.h>
int main()
{
	char *args[] = {"ls","-l",NULL};
	printf("Before execvp\n");
	execvp("ls",args);
	printf("execvp failed\n");
	return 0;
}
