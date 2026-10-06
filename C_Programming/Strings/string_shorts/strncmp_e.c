#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[] = "Embedded";
    char str2[] = "Embed";

    if(strncmp(str1, str2, 5) == 0)
        printf("First 5 characters are equal\n");
    else
        printf("First 5 characters are different\n");

    return 0;
}
