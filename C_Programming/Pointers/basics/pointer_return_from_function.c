#include <stdio.h>

int *getValue(void)
{
    static int a = 100;

    return &a;
}

int main(void)
{
    int *p;

    p = getValue();

    printf("Value = %d\n", *p);

    return 0;
}
