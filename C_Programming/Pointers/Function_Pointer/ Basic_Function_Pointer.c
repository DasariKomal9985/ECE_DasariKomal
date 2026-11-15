#include <stdio.h>

void display(void)
{
    printf("Hello from function pointer\n");
}

int main(void)
{
    void (*ptr)(void);

    ptr = display;

    ptr();

    return 0;
}