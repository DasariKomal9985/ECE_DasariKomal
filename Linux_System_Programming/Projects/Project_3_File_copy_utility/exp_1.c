#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int src, dest;
    char buffer[1024];
    ssize_t bytes;

    if (argc != 3)
    {
        printf("Usage: %s source destination\n", argv[0]);
        return 1;
    }

    src = open(argv[1], O_RDONLY);

    if (src == -1)
    {
        perror("Source file");
        return 1;
    }

    dest = open(argv[2],
                O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (dest == -1)
    {
        perror("Destination file");
        close(src);
        return 1;
    }

    while ((bytes = read(src, buffer, sizeof(buffer))) > 0)
    {
        ssize_t total = 0;

        while (total < bytes)
        {
            ssize_t n = write(dest, buffer + total,
                              bytes - total);

            if (n <= 0)
            {
                perror("write");
                close(src);
                close(dest);
                return 1;
            }

            total += n;
        }
    }

    if (bytes == -1)
    {
        perror("read");
        close(src);
        close(dest);
        return 1;
    }

    close(src);
    close(dest);

    printf("File copied successfully!\n");

    return 0;
}




/*



▶️ How to compile and run
1. Create a source file
echo "Welcome to Linux System Programming" > source.txt


2. Compile the code
gcc file_copy.c -o file_copy


3. Copy the file
./file_copy source.txt destination.txt


4. Verify the destination
cat destination.txt


Expected output:
Welcome to Linux System Programming


⚙️ System calls used
System call	Purpose
open()	Opens source and destination files
read()	Reads data from the source
write()	Writes data to the destination
close()	Closes both file descriptors

Note: This utility overwrites an existing destination file. Do not use the same file as both source and destination.

One-line definition: A file copy utility copies file contents from one file to another using Linux system calls.



*/
