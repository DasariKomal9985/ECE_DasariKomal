#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    int flags;

    fd = open("test.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    flags = fcntl(fd, F_GETFL);

    if (flags == -1)
    {
        perror("fcntl");
        close(fd);
        return 1;
    }

    if ((flags & O_ACCMODE) == O_RDONLY)
        printf("File opened for reading\n");
    else if ((flags & O_ACCMODE) == O_WRONLY)
        printf("File opened for writing\n");
    else if ((flags & O_ACCMODE) == O_RDWR)
        printf("File opened for reading and writing\n");

    close(fd);

    return 0;
}





/*
 
   
   🔹 fcntl() System Call in Linux ⚙️
The fcntl() system call is used to control and modify the properties of an open file descriptor.
For example, we can get file descriptor flags, change file status flags, or duplicate a descriptor.




🔍 Explanation
Code				Purpose
open()			Opens the file
fcntl(fd, F_GETFL)	Gets the file status flags
O_RDONLY		Read-only mode
O_WRONLY		Write-only mode
O_RDWR			Read and write mode
close(fd)		Closes the file descriptor



📌 Common fcntl() commands
Command	Purpose
F_GETFL	Get file status flags
F_SETFL	Change certain file status flags
F_GETFD	Get file descriptor flags
F_SETFD	Set file descriptor flags
F_DUPFD	Duplicate a descriptor using an available descriptor number



📌 Return values
- Success: Depends on the command; often returns a non-negative value.
- Failure: Returns -1 and sets errno.


▶️ How to run
echo "Hello Linux" > test.txt
gcc fcntl.c -o fcntl_demo
./fcntl_demo


File opened for reading


One-line definition: fcntl() is a Linux system call used to get or modify file descriptor settings and perform descriptor-related operations.
*/
