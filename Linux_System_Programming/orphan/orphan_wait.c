#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

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
		sleep(3);
		printf("Child fineshed\n");
	}
	else
	{
		printf("Parent Pid = %d\n",getpid());
		printf("Child PID = %d\n",pid);
		printf("parent waiting for child...\n");
		wait(NULL);
		printf("Child finished, Parent exiting...\n");
	}
	return 0;
}
