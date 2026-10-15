#include <stdio.h>

volatile int flag = 0;

int main()
{
    while (flag == 0)
    {
        printf("Waiting...\n");
        break;
    }

    printf("Program completed\n");

    return 0;
}
