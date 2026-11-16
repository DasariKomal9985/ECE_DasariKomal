Concept: The callback returns an integer value to process().





#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

void process(int (*callback)(int, int))
{
    int result = callback(10, 20);

    printf("Result = %d\n", result);
}

int main(void)
{
    process(add);

    return 0;
}