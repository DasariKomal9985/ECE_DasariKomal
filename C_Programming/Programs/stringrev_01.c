#include <stdio.h>

int main(void)
{
    char str[100];
    int len = 0, i;

    printf("Enter a string: ");
    scanf("%99s", str);

    while (str[len] != '\0')
    {
        len++;
    }

    for (i = len - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }

    printf("\n");

    return 0;
}
