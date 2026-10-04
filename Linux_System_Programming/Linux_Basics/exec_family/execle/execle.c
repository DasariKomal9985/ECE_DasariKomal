#include<stdio.h>
#include<unistd.h>
int main()
{
	char *env[] = {"My_Name = Komal","My_Project = LSP",NULL};
	printf("Before execle()\n");
	execle("/usr/bin/env","env",NULL,env);
	printf("execle failed\n");
	return 0;
}
