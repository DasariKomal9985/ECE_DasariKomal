#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main()
{
	pid_t pid;

	pid = fork();

	if(pid < 0)
	{
		perror("fork");
		return 1;
	}
	if(pid == 0)
	{
		printf("Child PID = %d\n",getpid());
		printf("Child Exit\n");
		exit(10);
	}
	else
	{
		printf("Parent PID = %d\n",getpid());
		printf("Child PID = %d\n",pid);
		printf("Parent waiting for child...\n");
	       	wait(NULL);
		printf("Parent : Child Collection..\n");	
	}
	return 0;
}
