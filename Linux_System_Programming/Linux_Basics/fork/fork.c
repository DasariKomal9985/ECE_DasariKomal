#include <stdio.h>
#include <unistd.h>
int main()
{
	pid_t pid;
	printf("Before fork : PID = %d\n",getpid());
	pid = fork();
	if(pid < 0)
	{
		printf("fork failed\n");
	}
	else if(pid == 0)
	{
		printf("\n--CHILD--\n");
		printf("Child PID = %d\n",getpid());
		printf("Parent PID = %d\n",getppid());
	}
	else
	{
		printf("\n--Parent--\n");
		printf("Parent PID = %d\n",getpid());
		printf("Child PID = %d\n",pid);
	}
	return 0;
}
