#include <stdio.h>

int main(void)
{
    volatile int flag = 0;

    flag = 1;

    printf("Flag = %d\n", flag);

    return 0;
}
