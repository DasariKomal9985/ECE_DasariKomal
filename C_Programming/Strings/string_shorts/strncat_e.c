#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[30] = "Embedded ";
    char str2[] = "Systems";

    strncat(str1, str2, 3);

    printf("Result = %s\n", str1);

    return 0;
}
