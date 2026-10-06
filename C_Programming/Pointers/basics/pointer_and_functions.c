#include <stdio.h>

void display(int *p)
{
    printf("Value = %d\n", *p);
}

int main(void)
{
    int a = 10;

    display(&a);

    return 0;
}
