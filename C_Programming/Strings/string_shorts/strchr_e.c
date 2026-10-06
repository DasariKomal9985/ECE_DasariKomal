#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[] = "Embedded";
    char *p;

    p = strchr(str, 'e');

    if(p != NULL)
        printf("Character found: %s\n", p);
    else
        printf("Character not found\n");

    return 0;
}
