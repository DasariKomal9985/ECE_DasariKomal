#include <stdio.h>

#define ADD(a, b) ((a) + (b))

int main(void)
{
    int result;

    result = ADD(10, 20);

    printf("Result = %d\n", result);

    return 0;
}
