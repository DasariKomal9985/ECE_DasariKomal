#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	pid_t pid;
	pid = fork();
	if(pid <0)
	{
		perror("fork");
		return 1;
	}
	if(pid == 0)
	{
		printf("Child PID = %d\n",getpid());
		printf("Child Exit :...\n");
		exit(10);
	}
	else
	{
	printf("Parent PID = %d\n",getpid());
	printf("Child PID = %d\n",pid);
	printf("Parent : Sleeping for 30 Sec....\n");
	sleep(30);
	printf("Parent: exit...\n");
	}
	return 0;
}
