#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[] = "Embedded";
    int start = 0;
    int end = strlen(str) - 1;
    char temp;

    while(start < end)
    {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }

    printf("Reversed = %s\n", str);

    return 0;
}
