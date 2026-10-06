#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int main(void)
{
    int (*fp)(int, int);

    fp = add;

    printf("Result = %d\n", fp(10, 20));

    return 0;
}
