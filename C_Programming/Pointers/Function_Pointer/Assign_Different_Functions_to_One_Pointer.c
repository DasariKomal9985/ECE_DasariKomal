Concept: The same pointer can select different functions with compatible signatures.





#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int main(void)
{
    int (*ptr)(int, int);

    ptr = add;
    printf("Addition = %d\n", ptr(20, 10));

    ptr = sub;
    printf("Subtraction = %d\n", ptr(20, 10));

    return 0;
}