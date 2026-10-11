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
        perror("Source open");
        return 1;
    }

    dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (dest == -1)
    {
        perror("Destination open");
        close(src);
        return 1;
    }

    while ((bytes = read(src, buffer, sizeof(buffer))) > 0)
    {
        ssize_t written = 0;

        while (written < bytes)
        {
            ssize_t n = write(dest, buffer + written,
                              bytes - written);

            if (n <= 0)
            {
                perror("write");
                close(src);
                close(dest);
                return 1;
            }

            written += n;
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
echo "Hello Linux System Programming" > source.txt


2. Compile the program
gcc mycp.c -o mycp


3. Run your own copy command
./mycp source.txt destination.txt


4. Verify the copied content
cat destination.txt


Output:
Hello Linux System Programming


⚙️ How it works
Source file
source.txt

read()
Reads bytes into a buffer

write()
Writes bytes from the buffer

Destination file
destination.txt


Important: This is a basic learning implementation. It overwrites an existing destination file and does not preserve all metadata like the original cp command. Avoid using the same file as both source and destination.



*/
