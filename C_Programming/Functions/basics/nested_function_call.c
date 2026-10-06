#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int square(int x)
{
    return x * x;
}

int main(void)
{
    int result = square(add(2, 3));

    printf("Result = %d\n", result);

    return 0;
}
