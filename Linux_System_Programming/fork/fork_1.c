
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid;

    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return 1;
    }
    else if (pid == 0)
    {
        printf("Child process\n");
        printf("Child PID: %d\n", getpid());
    }
    else
    {
        printf("Parent process\n");
        printf("Parent PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);
    }

    return 0;
}



/*




🔀 fork() in Linux System Programming
1. What is fork()?
fork() is a Linux system call used to create a new process called a child process from the existing process called the parent process.
After fork() succeeds, both processes continue executing from the statement immediately after the fork() call.



2. Syntax
pid_t fork(void);


Include these header files:
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>


4. Compile and run ⚙️
gcc fork.c -o fork
./fork


Example output (order may vary):
Parent process
Parent PID: 2500
Child PID: 2501
Child process
Child PID: 2501


The PIDs above are examples; your system will show different values.




5. Return values of fork()
Return value			Meaning
	-1		Process creation failed
	0		Code is executing in the child process
Positive value	Code is executing in the parent; value is the child's PID






6. How does fork() work?
Parent Process
Calls fork()

Parent
pid > 0


Child
pid == 0




Both processes have their own process IDs and execute independently. Their output order is not guaranteed.


7. Important points 💡

- fork() creates a child process.
- The child initially receives a copy of the parent's process state, with memory typically implemented using copy-on-write.
- Both processes continue after the fork() call.
- getpid() returns the current process ID.
- getppid() returns the parent process ID.


One-line definition: fork() creates a new child process from the calling process. 🚀













*/
