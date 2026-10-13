
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(void)
{
    int fd[2];
    pid_t pid;
    char message[] = "Hello from parent!";
    char buffer[100] = {0};

    if (pipe(fd) == -1)
    {
        perror("pipe");
        return 1;
    }

    pid = fork();

    if (pid == -1)
    {
        perror("fork");
        close(fd[0]);
        close(fd[1]);
        return 1;
    }

    if (pid == 0)
    {
        /* Child reads from the pipe */
        close(fd[1]);

        ssize_t n = read(fd[0], buffer, sizeof(buffer) - 1);

        if (n > 0)
        {
            buffer[n] = '\0';
            printf("Child received: %s\n", buffer);
        }

        close(fd[0]);
    }
    else
    {
        /* Parent writes to the pipe */
        close(fd[0]);

        if (write(fd[1], message, strlen(message)) == -1)
            perror("write");

        close(fd[1]);
        wait(NULL);
    }

    return 0;
}




/*



1. What is IPC?
IPC (Inter-Process Communication) is a mechanism that allows two or more processes to exchange data.
Common IPC methods:
- Pipe
- Message Queue
- Shared Memory
- Socket



2. What is a Pipe?
A pipe is an IPC mechanism that allows one process to send data to another process through a byte stream.
Usually, one process writes data into the pipe, and another process reads it.


Process 1
Writes data ✍️

Pipe
Temporary kernel buffer

Process 2
Reads data 📖


3. pipe() system call
Syntax
#include <unistd.h>

int pipe(int pipefd[2]);


The array contains two file descriptors:
File descriptor	Purpose
pipefd[0]	Read end
pipefd[1]	Write end


Return value:
- 0 — success
- -1 — failure



5. Compile and run ⚙️
Save the program as pipe.c.
gcc pipe.c -o pipe_demo
./pipe_demo


Output:
Child received: Hello from parent!


6. How does it work?
1. pipe(fd) creates the pipe and provides read/write file descriptors.
2. fork() creates the child process, which inherits these descriptors.
3. The parent closes the read end and writes the message.
4. The child closes the write end and reads the message.
5. Both processes close their descriptors when finished.

7. Important points 💡

- An ordinary pipe is typically used between related processes, such as a parent and child.
- Pipes transfer a stream of bytes, not separate messages with built-in boundaries.
- A pipe is unidirectional in its normal use; two pipes can be used for two-way communication.
- read() and write() transfer data through the pipe.
- close() is important: keeping unnecessary write ends open can prevent a reader from receiving end-of-file.

One-line definition: A pipe is an IPC mechanism that transfers a stream of bytes from one process to another through the kernel. 🚀



*/

