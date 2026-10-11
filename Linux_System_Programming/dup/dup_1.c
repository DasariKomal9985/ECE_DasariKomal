#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd, new_fd;
    char buffer[20] = {0};

    fd = open("test.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    new_fd = dup(fd);

    if (new_fd == -1)
    {
        perror("dup");
        close(fd);
        return 1;
    }

    read(fd, buffer, 5);
    printf("First read: %s\n", buffer);

    char second[20] = {0};
    read(new_fd, second, 5);
    printf("Second read: %s\n", second);

    close(fd);
    close(new_fd);

    return 0;
}






/*
 
 🔹 Why do we use dup()?
The main use of dup() is to use the same open file through another file descriptor, especially when redirecting input or output.



🔍 Explanation
- open() opens test.txt and returns a file descriptor.
- dup(fd) creates another file descriptor for the same open file.
- Both descriptors share the same file offset. Reading through one advances the position seen by the other.
- close() closes each descriptor separately.



📌 Return values
Return value	Meaning
0 or a positive integer	Success; returns the new file descriptor
-1	Failure; sets errno
Example: If open() returns 3, dup(3) might return 4. The actual numbers can vary.



🔹 Real use: Redirecting output
Suppose you want the output of printf() to go into a file instead of the terminal. dup2() is commonly used for this.


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("output.txt",
                  O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    if (dup2(fd, STDOUT_FILENO) == -1)
    {
        perror("dup2");
        close(fd);
        return 1;
    }

    close(fd);

    printf("Hello, file!\n");
    fflush(stdout);

    return 0;
}


Result: Hello, file! is written to output.txt instead of appearing on the terminal.
📌 Remember
- dup() — creates another file descriptor for the same open file.
- dup2() — duplicates a file descriptor onto a specified descriptor, often for input/output redirection.
- In Linux shells, redirection such as command > output.txt relies on this kind of file-descriptor manipulation.
One-line definition: We use dup() to create another handle for the same open file, which is useful for sharing access and managing input/output redirection. 👍




🔹 Important terms in dup()
Term						Simple meaning
Same FD					Both variables contain the same descriptor number.
Different FDs				Two different descriptor numbers, such as 3 and 4.
Same file				Both descriptors refer to the same underlying file.
Same open file description		Both descriptors share the file position and file status flags.
Same file position			Both use the same current read/write offset.
Independent file positions		Each open file description has its own offset.



💻 Example
int fd = open("test.txt", O_RDONLY);
int new_fd = dup(fd);


Suppose open() returns 3.
- fd = 3
- new_fd = 4
So, the descriptor numbers are different, but both refer to the same open file description.
fd = 3

Both refer to the same open file description

Shared file position and status flags


new_fd = 4


🔹 What if we use open() twice?
int fd1 = open("test.txt", O_RDONLY);
int fd2 = open("test.txt", O_RDONLY);


Now, both descriptors open the same file, but they have independent file positions because each open() creates a separate open file description.
📌 Remember these three cases
Code	File descriptors	File position
dup(fd)	Different numbers	Shared
open() twice	Different numbers	Independent
int fd2 = fd1;	Same number	Same descriptor, not a new FD
 
 */
