#include <stdio.h>

int square(int n)
{
    return n * n;
}

int main(void)
{
    int result = square(5);

    printf("Square = %d\n", result);

    return 0;
}
