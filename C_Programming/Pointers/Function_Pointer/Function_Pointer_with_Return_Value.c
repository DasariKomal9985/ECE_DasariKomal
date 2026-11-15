Concept: Function pointer calls a function that returns an integer.

#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int main(void)
{
    int (*ptr)(int, int);

    ptr = add;

    int result = ptr(10, 20);

    printf("Sum = %d\n", result);

    return 0;
}