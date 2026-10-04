#include<stdio.h>
#include<unistd.h>
int main()
{
	char *args[] = {"env",NULL};
	char *env[] = {"My_Name = komal","My_Project = LSP",NULL};
	printf("Before execve \n");
	execve("/usr/bin/env",args,env);
	printf("execve failed\n");
	return 0;
}
