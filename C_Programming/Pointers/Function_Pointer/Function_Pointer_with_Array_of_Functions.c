Concept: ptr[3] is an array containing three function pointers.





#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int mul(int a, int b)
{
    return a * b;
}

int main(void)
{
    int (*ptr[3])(int, int) = {add, sub, mul};

    printf("Addition = %d\n", ptr[0](10, 5));
    printf("Subtraction = %d\n", ptr[1](10, 5));
    printf("Multiplication = %d\n", ptr[2](10, 5));

    return 0;
}