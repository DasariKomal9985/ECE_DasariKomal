#include <stdio.h>

int main(void)
{
    char str[] = "Embedded";
    char *p = str;

    while(*p != '\0')
    {
        printf("%c", *p);
        p++;
    }

    printf("\n");

    return 0;
}
