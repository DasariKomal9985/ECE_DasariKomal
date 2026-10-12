#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid = fork();

    if (pid == 0)
    {
        printf("Child PID: %d\n", (int)getpid());
        printf("Child's Parent PID: %d\n", (int)getppid());
    }
    else if (pid > 0)
    {
        printf("Parent PID: %d\n", (int)getpid());
        printf("Child PID: %d\n", (int)pid);
    }

    return 0;
}






/*



🆔 getpid() and getppid() in Linux System Programming

These functions help us identify a process and its parent process in Linux.
1. getpid()
Definition: getpid() returns the Process ID (PID) of the currently running process.
Syntax
#include <unistd.h>

pid_t getpid(void);


- Returns the current process's PID.
- Does not take any arguments.



2. getppid()
Definition: getppid() returns the Parent Process ID (PPID) of the currently running process.
Syntax
#include <unistd.h>

pid_t getppid(void);


- Returns the PID of the process that created the current process.
- If the parent terminates, the process may be adopted by another system process.

Compile and run ⚙️
gcc process_id.c -o process_id
./process_id


Example output:
Process ID (PID): 2450
Parent Process ID (PPID): 2300


These numbers are examples; your output will be different.



4. Difference between getpid() and getppid()
Function	Returns			Meaning
getpid()	Current PID	ID of this process
getppid()	Parent PID	ID of its parent process


Here, fork() creates the child, getpid() identifies the process currently running, and getppid() identifies its parent.

Remember: PID = my process ID; PPID = my parent's process ID. 🚀






*/
