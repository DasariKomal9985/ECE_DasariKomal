#include <stdio.h>

int main(void)
{
    char str[] = "Embedded Systems";
    int count = 0;

    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == 'a' || str[i] == 'e' ||
           str[i] == 'i' || str[i] == 'o' ||
           str[i] == 'u')
        {
            count++;
        }
    }

    printf("Vowels = %d\n", count);

    return 0;
}
