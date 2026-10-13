#include <stdio.h>
#include <string.h>
#include <sys/mman.h>

int main(void)
{
    size_t size = 4096;

    char *ptr = mmap(NULL, size,
                     PROT_READ | PROT_WRITE,
                     MAP_PRIVATE | MAP_ANONYMOUS,
                     -1, 0);

    if (ptr == MAP_FAILED)
    {
        perror("mmap");
        return 1;
    }

    strcpy(ptr, "Anonymous memory mapping");

    printf("%s\n", ptr);

    if (munmap(ptr, size) == -1)
    {
        perror("munmap");
        return 1;
    }

    return 0;
}
