#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main()
{
    int fd;
    struct stat file_info;

    fd = open("test.txt", O_RDONLY);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    if (fstat(fd, &file_info) == -1)
    {
        perror("fstat");
        close(fd);
        return 1;
    }

    printf("File size: %lld bytes\n",
           (long long)file_info.st_size);

    printf("File permissions: %o\n",
           (unsigned int)(file_info.st_mode & 0777));

    close(fd);

    return 0;
}






/*

🔹 fstat() System Call in Linux 📂
The fstat() system call is used to get information about a file using its file descriptor.
Unlike stat(), which uses a filename, fstat() uses a file descriptor obtained from open().


🔍 Explanation
Code			Purpose
open()			Opens the file and returns a file descriptor
struct stat		Stores file metadata
fstat(fd, &file_info)	Gets information about the opened file
st_size			File size in bytes
st_mode			File type and permissions
close(fd)		Closes the file descriptor



📌 Return values
Return value	Meaning
0	Success
-1	Failure; errno indicates the error



⚙️ Difference between stat() and fstat()

stat()									fstat()
Uses a filename/path.						Uses a file descriptor.
stat("test.txt", &info)						fstat(fd, &info)
Does not require the file to be opened first.			Requires a valid open file descriptor.

One-line definition: fstat() retrieves file metadata using an existing file descriptor. 😊


*/
