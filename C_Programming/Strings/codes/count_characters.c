#include <stdio.h>

int main(void)
{
    char str[] = "Embedded";
    int count = 0;

    for(int i = 0; str[i] != '\0'; i++)
    {
        count++;
    }

    printf("Characters = %d\n", count);

    return 0;
}
