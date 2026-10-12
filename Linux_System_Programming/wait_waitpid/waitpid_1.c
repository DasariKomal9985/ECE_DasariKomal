
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
        return 10;
    }
    else if (pid > 0)
    {
        waitpid(pid, &status, 0);

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

Syntax
pid_t waitpid(pid_t pid, int *status, int options);


Unlike wait(), waitpid() lets you specify which child process to wait for and whether to wait or return immediately.
- pid: Selects the child process.
- status: Receives the child's status.
- options: Controls waiting behavior, such as 0 to wait or WNOHANG to return immediately if no child has changed state.



Compile and run:
gcc waitpid.c -o waitpid
./waitpid


Output:
Child process running
Child exit status: 10



3. Difference between wait() and waitpid()
Feature				wait()			waitpid()
Child selection			Any child		Specific child or group
Blocking			Waits by default	Depends on options
Non-blocking option		No direct option	WNOHANG
Header file			<sys/wait.h>		<sys/wait.h>
Return value			Child PID or -1		Child PID, 0 in certain non-blocking cases, or -1



4. Important status macros 💡
- WIFEXITED(status) — checks whether the child exited normally.
- WEXITSTATUS(status) — retrieves the child's exit code when it exited normally.
- WIFSIGNALED(status) — checks whether the child terminated because of a signal.


One-line definitions:

- wait() — waits for any child process to terminate and collects its status.

- waitpid() — waits for a selected child process or checks its status according to the specified options. 🚀


*/
