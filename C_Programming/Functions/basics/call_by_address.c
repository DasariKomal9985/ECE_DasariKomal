#include <stdio.h>

void change(int *x)
{
    *x = 50;
}

int main(void)
{
    int a = 10;

    change(&a);

    printf("a = %d\n", a);

    return 0;
}
