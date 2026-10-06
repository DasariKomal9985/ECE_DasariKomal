#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[] = "Embedded-C-Linux";
    char *token;

    token = strtok(str, "-");

    while(token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, "-");
    }

    return 0;
}
