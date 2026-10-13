
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

int main(void)
{
    const char *filename = "demo.txt";
    const char *message = "Hello Linux mmap!";
    size_t len = strlen(message) + 1;

    int fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    /* Make the file large enough for the mapping */
    if (ftruncate(fd, (off_t)len) == -1)
    {
        perror("ftruncate");
        close(fd);
        return 1;
    }

    char *ptr = mmap(NULL, len,
                     PROT_READ | PROT_WRITE,
                     MAP_SHARED, fd, 0);

    if (ptr == MAP_FAILED)
    {
        perror("mmap");
        close(fd);
        return 1;
    }

    /* Write directly through the mapped memory */
    memcpy(ptr, message, len);

    if (msync(ptr, len, MS_SYNC) == -1)
    {
        perror("msync");
    }

    printf("Mapped memory contains: %s\n", ptr);

    if (munmap(ptr, len) == -1)
    {
        perror("munmap");
        close(fd);
        return 1;
    }

    close(fd);

    printf("Memory mapping removed successfully.\n");

    return 0;
}

