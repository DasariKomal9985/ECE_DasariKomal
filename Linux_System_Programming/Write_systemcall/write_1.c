#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd;
    char data[] = "Hello Linux\n";
    ssize_t bytes;

    fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    bytes = write(fd, data, strlen(data));

    if (bytes == -1)
    {
        perror("write");
        close(fd);
        return 1;
    }

    printf("Bytes written: %zd\n", bytes);

    close(fd);
    return 0;
}







/*
 
 🔹 write() System Call in Linux ✍️
The write() system call is used to write data from a memory buffer to a file or another file descriptor, such as the terminal.



🔍 Explanation
Code					Purpose
open()					Opens or creates the file
O_WRONLY				Opens the file for writing
O_CREAT					Creates the file if it doesn't exist
O_TRUNC					Erases existing contents when opening a regular file for writing
write(fd, data, strlen(data))		Writes the data into the file
close(fd)				Closes the file



🔄 write() syntax
write(file_descriptor, buffer, number_of_bytes);


- file_descriptor — identifies where to write.
- buffer — contains the data to write.
- number_of_bytes — maximum number of bytes to write.



📌 Return values
Return value	Meaning
Positive number	Number of bytes written
0	No bytes written
-1	Error occurred; check errno



gcc write.c -o write
./write
cat test.txt


Bytes written: 12
Hello Linux
 
 */
