#include <stdio.h>

int main(void)
{
    char str[] = "EMBEDDED";

    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 32;
        }
    }

    printf("%s\n", str);

    return 0;
}
