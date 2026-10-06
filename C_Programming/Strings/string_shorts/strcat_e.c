#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[30] = "Embedded ";
    char str2[] = "Systems";

    strcat(str1, str2);

    printf("Result = %s\n", str1);

    return 0;
}
