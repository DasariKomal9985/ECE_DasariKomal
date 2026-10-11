#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    char buffer[100];
    ssize_t bytes;

    fd = open("test.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("open");
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

    printf("Data: %s", buffer);
    printf("\nBytes read: %zd\n", bytes);

    close(fd);

    return 0;
}





/*
 read() System Call in Linux 📖
The read() system call is used to read data from a file or another file descriptor into a buffer.



🔍 Explanation
Code							Purpose
open()						Opens the file
buffer[100]					Stores the data read from the file
read(fd, buffer, sizeof(buffer) - 1)		Reads up to 99 bytes
buffer[bytes] = '\0'				Adds a string terminator so printf() can display the data safely
close(fd)					Closes the file




🔄 read() syntax
read(file_descriptor, buffer, number_of_bytes);


- file_descriptor — identifies the open file.
- buffer — memory where the read data is stored.
- number_of_bytes — maximum number of bytes to read.




📌 Return values
Return value	Meaning
Positive number	Number of bytes successfully read
0	End of file (EOF) reached
-1	Error occurred; check errno




echo "Hello Linux" > test.txt
gcc read.c -o read
./read
 
 */
