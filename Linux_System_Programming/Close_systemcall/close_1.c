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

    printf("File opened successfully\n");

    if (close(fd) == -1)
    {
        perror("close");
        return 1;
    }

    printf("File closed successfully\n");

    return 0;
}



/*
 
 🔍 Explanation
Code				Purpose
open()				Opens the file
fd				Stores the file descriptor
close(fd)			Closes the file descriptor
perror()			Displays an error message if a call fails


📌 Return values
Return value			Meaning
0			Success
-1			Failure; errno indicates the error



gcc close.c -o close
./close
 
 */
