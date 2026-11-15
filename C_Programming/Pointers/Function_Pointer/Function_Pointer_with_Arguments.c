#include <stdio.h>

void display(int a)
{
    printf("Value = %d\n", a);
}

int main(void)
{
    void (*ptr)(int);

    ptr = display;

    ptr(100);

    return 0;
}




Concept: Function pointer accepts an integer argument.