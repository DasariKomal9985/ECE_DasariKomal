Concept: A structure can contain function pointer members. This technique is useful in device driver operation tables.





#include <stdio.h>

struct Calculator
{
    int (*add)(int, int);
    int (*sub)(int, int);
};

int addition(int a, int b)
{
    return a + b;
}

int subtraction(int a, int b)
{
    return a - b;
}

int main(void)
{
    struct Calculator c;

    c.add = addition;
    c.sub = subtraction;

    printf("Addition = %d\n", c.add(20, 10));
    printf("Subtraction = %d\n", c.sub(20, 10));

    return 0;
}