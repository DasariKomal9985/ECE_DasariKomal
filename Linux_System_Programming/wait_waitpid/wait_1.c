
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0)
    {
        printf("Child process running\n");
        return 5;
    }
    else if (pid > 0)
    {
        wait(&status);

        if (WIFEXITED(status))
        {
            printf("Child exit status: %d\n",
                   WEXITSTATUS(status));
        }
    }
    else
    {
        perror("fork");
        return 1;
    }

    return 0;
}






/*


⏳ wait() and waitpid() in Linux System Programming
Both wait() and waitpid() are used by a parent process to wait for a child process to change state, commonly to finish execution and collect its exit status.

1. wait()
Syntax
#include <sys/wait.h>
#include <unistd.h>

pid_t wait(int *status);


- Waits for any child process to terminate.
- Stores the child's termination status in status.
- Returns the terminated child's PID on success, or -1 on failure.




Compile and run:
gcc wait.c -o wait
./wait


Output:
Child process running
Child exit status: 5


Here, the parent waits until the child terminates and retrieves its exit status.

*/
