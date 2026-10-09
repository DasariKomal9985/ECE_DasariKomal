#include<stdio.h>
#include<unistd.h>
int main()
{
	printf("Before evecl()\n");
	execl("/bin/ls","ls","-l",NULL);
	printf("After execl()\n");
	return 0;
}
