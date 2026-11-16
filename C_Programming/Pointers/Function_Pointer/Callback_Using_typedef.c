#include <stdio.h>

typedef void (*Callback)(void);

void display(void)
{
    printf("Callback executed\n");
}

void process(Callback ptr)
{
    ptr();
}

int main(void)
{
    process(display);

    return 0;
}