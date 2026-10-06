#include <stdio.h>

int add(int, int);

int main(void)
{
    int result = add(10, 20);

    printf("Result = %d\n", result);

    return 0;
}

int add(int a, int b)
{
    return a + b;
}
