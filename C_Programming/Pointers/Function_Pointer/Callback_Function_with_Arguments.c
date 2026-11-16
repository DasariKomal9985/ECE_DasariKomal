Concept: The callback accepts an integer argument

#include <stdio.h>

void display(int a)
{
    printf("Value = %d\n", a);
}

void process(void (*callback)(int))
{
    callback(100);
}

int main(void)
{
    process(display);

    return 0;
}