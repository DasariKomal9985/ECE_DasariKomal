#include <stdio.h>
#include <unistd.h>

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
		printf("Parent PID = %d\n",getppid());
		sleep(5);
		printf("\n After Parent Terminates:\n");
		printf("Child PID = %d\n",getpid());
		printf("Parent PID = %d\n",getppid());
	}
	else
	{
		printf("Parent PID = %d\n",getpid());
		printf("Child PID = %d\n",pid);
		printf("Parent is terminating...\n");
		return 0;
	}
	return 0;
}
