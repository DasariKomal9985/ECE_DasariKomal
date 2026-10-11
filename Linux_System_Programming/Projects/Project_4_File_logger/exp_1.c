#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd;
    char message[200];

    fd = open("log.txt",
              O_WRONLY | O_CREAT | O_APPEND,
              0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    printf("Enter log message: ");

    if (fgets(message, sizeof(message), stdin) == NULL)
    {
        close(fd);
        return 1;
    }

    size_t len = strlen(message);
    size_t written = 0;

    while (written < len)
    {
        ssize_t n = write(fd, message + written, len - written);

        if (n <= 0)
        {
            perror("write");
            close(fd);
            return 1;
        }

        written += (size_t)n;
    }

    printf("Log saved successfully!\n");

    close(fd);

    return 0;
}






/*



▶️ How to compile and run
1. Compile
gcc file_logger.c -o file_logger


2. Run
./file_logger


3. Enter a message
Enter log message: Application started
Log saved successfully!


4. View the log file
cat log.txt


Output:
Application started


Run the program again with another message. Because we use O_APPEND, the new message is added to the end without deleting previous logs.

🔍 System calls used
Function	Purpose
open()	Opens or creates the log file
write()	Writes the message to the log
close()	Closes the file descriptor

One-line definition: A file logger records messages in a file using Linux file-handling system calls. 📝



*/
