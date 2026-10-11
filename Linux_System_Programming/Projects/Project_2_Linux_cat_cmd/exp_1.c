#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int fd;
    char buffer[1024];
    ssize_t bytes;

    if (argc != 2)
    {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    fd = open(argv[1], O_RDONLY);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    while ((bytes = read(fd, buffer, sizeof(buffer))) > 0)
    {
        ssize_t written = 0;

        while (written < bytes)
        {
            ssize_t n = write(STDOUT_FILENO,
                              buffer + written,
                              bytes - written);

            if (n <= 0)
            {
                perror("write");
                close(fd);
                return 1;
            }

            written += n;
        }
    }

    if (bytes == -1)
    {
        perror("read");
        close(fd);
        return 1;
    }

    close(fd);

    return 0;
}







/*


▶️ How to compile and run
1. Create a test file
echo "Hello Linux System Programming" > test.txt


2. Compile your program
gcc mycat.c -o mycat


3. Run your own cat command
./mycat test.txt


Output:
Hello Linux System Programming


⚙️ How it works
open()
Opens the file

read()
Reads bytes into the buffer

write()
Sends the bytes to the terminal

close()
Closes the file


One-line project definition: Implement the Linux cat command in C using open(), read(), write(), and close() system calls. 🚀



*/
