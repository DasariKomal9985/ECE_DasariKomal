#include <stdio.h>

int multiply(int, int);

int main(void)
{
    int result = multiply(5, 4);

    printf("Result = %d\n", result);

    return 0;
}

int multiply(int a, int b)
{
    return a * b;
}
