#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;

    fd = open("test.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    printf("File descriptor: %d\n", fd);

    close(fd);

    return 0;
}





/*

🔹 File Descriptor in Linux 📂
A file descriptor (FD) is a non-negative integer that a process uses to identify an open file or another input/output resource.
For example, when you open a file using open(), Linux returns a file descriptor.




Example output:
File descriptor: 3


The number may vary depending on which descriptors are already in use.



Standard File Descriptors
Linux normally provides these three standard file descriptors:
FD	Name	Purpose
0	stdin	Standard input, usually the keyboard
1	stdout	Standard output, usually the terminal
2	stderr	Standard error, usually the terminal




🔹 How does it work?
C Program
Calls open("test.txt", O_RDONLY)

Linux Kernel
Opens the file and returns FD 3

File Descriptor: 3
Used with read(), write(), and close()




📌 Important points
- open() returns a file descriptor on success and -1 on failure.
- read() uses the descriptor to read data.
- write() uses the descriptor to write data.
- close() releases the descriptor.


One-line definition: A file descriptor is an integer handle used by a process to access an open file or input/output resource in Linux. 😊

*/
