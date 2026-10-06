#include <stdio.h>

int main(void)
{
    char str[] = "embedded";

    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }
    }

    printf("%s\n", str);

    return 0;
}
