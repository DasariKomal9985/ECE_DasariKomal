#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd, new_fd;

    fd = open("test.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    new_fd = dup2(fd, 10);

    if (new_fd == -1)
    {
        perror("dup2");
        close(fd);
        return 1;
    }

    printf("Original FD: %d\n", fd);
    printf("New FD: %d\n", new_fd);

    close(fd);
    close(new_fd);

    return 0;
}




/*
 
 

🔹 dup2() System Call in Linux 📂
The dup2() system call duplicates one file descriptor onto a specific file descriptor number.
Unlike dup(), which automatically chooses an available descriptor number, dup2() lets you specify the number.





🔍 Explanation
Suppose open() returns 3.
new_fd = dup2(fd, 10);


- fd is 3.
- 10 is the descriptor number we request.
- dup2() makes descriptor 10 refer to the same open file description as descriptor 3.
- Both descriptors share the same file position and file status flags.


Output:
Original FD: 3
New FD: 10



📌 Return values
Return value	Meaning
newfd (here, 10)	Success
-1	Failure; errno indicates the error
If descriptor 10 was already open, dup2() closes it first and then redirects it to the same open file description as fd.



⚙️ Difference between dup() and dup2()
dup()							dup2()
Automatically chooses a free descriptor.	You specify the descriptor number.
dup(fd)						dup2(fd, 10)
Returns the new descriptor.			Returns the specified descriptor on success.



⭐ Real-world use: Output redirection
dup2() is commonly used to redirect standard output (STDOUT_FILENO, descriptor 1) to a file, such as when implementing shell commands like:
ls > output.txt


*/
