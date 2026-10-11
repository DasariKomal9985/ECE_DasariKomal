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

    printf("File opened successfully!\n");

    close(fd);

    return 0;
}




#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("test.txt", O_WRONLY);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    printf("File opened for writing\n");

    close(fd);
    return 0;
}



#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("test.txt", O_RDWR);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    printf("File opened for reading and writing\n");

    close(fd);
    return 0;
}





#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("newfile.txt",
                  O_WRONLY | O_CREAT,
                  0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    printf("File opened or created successfully\n");

    close(fd);
    return 0;
}





#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd = open("test.txt",
                  O_WRONLY | O_APPEND);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    char data[] = "New line\n";

    write(fd, data, strlen(data));

    printf("Data appended successfully\n");

    close(fd);
    return 0;
}



/*
 
🔹 open() System Call in Linux
The open() system call is used to open a file so that a program can read data from it or write data to it.


🔍 Explanation
- #include <fcntl.h> — provides open() and file access flags.
- open("test.txt", O_RDONLY) — opens test.txt in read-only mode.
- fd — stores the returned file descriptor, a number used to identify the opened file.
- fd == -1 — means the file could not be opened.
- close(fd) — closes the file when you finish using it.


⚙️ Common open() flags
Flag			Purpose
O_RDONLY	Open for reading
O_WRONLY	Open for writing
O_RDWR		Open for reading and writing
O_CREAT		Create the file if it doesn't exist
O_APPEND	Append data to the end of the file


 🔍 Return values of open()
Return value	Meaning
0 or a positive integer	Success; returns a file descriptor
-1	Failure; sets errno to indicate the error
Example: If open() returns 3, then fd = 3 is the file descriptor used to access that opened file. The number is assigned by the operating system and can vary.



▶️ How to run
Save as open.c, then run:
gcc open.c -o open
./open


Create a test file first if needed:
echo "Hello Linux" > test.txt
 
 */























