#include <stdio.h>

void display(void)
{
    printf("Callback executed\n");
}

void process(void (*callback)(void))
{
    printf("Processing...\n");

    callback();
}

int main(void)
{
    process(display);

    return 0;
}