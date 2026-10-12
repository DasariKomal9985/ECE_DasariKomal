
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void handle_signal(int sig)
{
    printf("\nSIGTERM received. Exiting...\n");
    exit(0);
}

int main()
{
    signal(SIGTERM, handle_signal);

    printf("Process PID: %d\n", (int)getpid());
    printf("Sending SIGTERM to this process...\n");

    sleep(1);

    if (kill(getpid(), SIGTERM) == -1)
    {
        perror("kill");
        return 1;
    }

    return 0;
}





/*





2. kill()
What is kill()?
kill() is a Linux/POSIX system call used to send a signal to a process. It can request a process to terminate, pause, or handle a signal, depending on the signal sent.
Syntax
#include <signal.h>
#include <sys/types.h>

int kill(pid_t pid, int sig);


- pid — identifies the target process.
- sig — signal to send, such as SIGTERM or SIGKILL.



Common signals

Signal				Number on Linux						Purpose
SIGTERM				15							Requests graceful termination
SIGKILL				9							Forces termination; cannot be caught or ignored
SIGSTOP				19 on common Linux architectures			Stops a process



Compile and run:
gcc kill.c -o kill_demo
./kill_demo


Example output:
Process PID: 2450
Sending SIGTERM to this process...

SIGTERM received. Exiting...





Return value of kill():
- 0 — signal sent successfully.
- -1 — failure, for example, an invalid PID or insufficient permission.



Note: kill() sends a signal; it does not necessarily terminate a process. The target process's response depends on the signal and its handling.




3. Difference between system() and kill()

Feature			system()			kill()
Type			C library function		System call
Purpose			Executes a shell command	Sends a signal to a process
Header			<stdlib.h>			<signal.h>
Example			system("ls")			kill(pid, SIGTERM)



One-line definitions:


- system() — executes a shell command from a C program.
- kill() — sends a specified signal to a process. 🚀
















*/
