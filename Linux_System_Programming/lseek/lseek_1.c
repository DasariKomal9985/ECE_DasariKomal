#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    char buffer[20];
    ssize_t bytes;

    fd = open("test.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    // Move file position to byte 6
    off_t pos = lseek(fd, 2, SEEK_SET);

    if (pos == (off_t)-1)
    {
        perror("lseek");
        close(fd);
        return 1;
    }

    bytes = read(fd, buffer, sizeof(buffer) - 1);

    if (bytes == -1)
    {
        perror("read");
        close(fd);
        return 1;
    }

    buffer[bytes] = '\0';

    printf("Data: %s\n", buffer);
    printf("Bytes read: %zd\n", bytes);

    close(fd);
    return 0;
}





/*
 
 🔹 lseek() System Call in Linux 📍
The lseek() system call is used to change the current position (file offset) within an open file. This allows us to read or write data from a specific location.




🔍 Explanation
Suppose test.txt contains:
Hello Linux


The statement:
lseek(fd, 6, SEEK_SET);


moves the file position to byte offset 6 (the character L in Linux). The next read() starts from that position.


Output:
Data: Linux
Bytes read: 5




📌 Syntax
lseek(fd, offset, whence);


Argument	Purpose
fd		File descriptor
offset		Number of bytes to move
whence		Reference point for the offset



⚙️ Common whence values

Value			Meaning
SEEK_SET	Position from the beginning of the file
SEEK_CUR	Position relative to the current position
SEEK_END	Position relative to the end of the file


📌 Return values

- Success: Returns the new file offset.
- Failure: Returns (off_t)-1 and sets errno.

One-line definition: lseek() is a Linux system call that changes the current file position for subsequent reading or writing. 😊

 
 */
