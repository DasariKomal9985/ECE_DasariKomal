#include <stdio.h>

static int count = 10;

void display(void)
{
    printf("Count = %d\n", count);
}

int main(void)
{
    display();

    count = 20;

    display();

    return 0;
}
