#include <stdio.h>

int main(void)
{
    char str[50];

    printf("Enter string: ");
    fgets(str, sizeof(str), stdin);

    printf("String = %s", str);

    return 0;
}
