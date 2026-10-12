
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Executing Linux command...\n");

    system("ls");

    return 0;
}





/*



1. system()

What is system()?
system() is a C standard library function used to execute a shell command from a C program.
Syntax
#include <stdlib.h>

int system(const char *command);



Compile and run:
gcc system.c -o system
./system


This program displays the files in the current directory by executing the ls command.

Return value: The command's status is returned in a wait-status format; -1 indicates a failure to execute the command or wait for it.

Important: system() is a library function, not a system call itself. Avoid passing untrusted input into shell commands.




*/
