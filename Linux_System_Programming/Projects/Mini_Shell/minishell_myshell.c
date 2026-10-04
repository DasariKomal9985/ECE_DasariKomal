#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
int main()
{
	char input[100];
	char *args[10];
	while(1)
	{
		printf("my_shell$");
		fflush(stdout);
		if(fgets(input, sizeof(input),stdin)==NULL)
		{
			break;
		}
		input[strcspn(input, "\n")] = '\0';
		if(strlen(input) == 0)
		{
			continue;
		}
		int i = 0;
		args[i] = strtok(input, " ");
		while(args[i] != NULL && i<9)
		{
			i++;
			args[i] = strtok(NULL, "");
		}
		pid_t pid = fork();
		if(pid < 0)
		{
			perror("fork");
		}
		else if(pid == 0)
		{
			execvp(args[0],args);
			perror("execvp");
			return 1;
		}
		else
		{
			waitpid(pid, NULL, 0);
		}
	}
	return 0;
}
