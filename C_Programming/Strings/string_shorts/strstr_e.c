#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[] = "Embedded Systems";
    char *p;

    p = strstr(str, "Systems");

    if(p != NULL)
        printf("Substring found: %s\n", p);
    else
        printf("Substring not found\n");

    return 0;
}
