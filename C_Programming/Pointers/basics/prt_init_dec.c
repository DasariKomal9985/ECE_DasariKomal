#include <stdio.h>

int main(void)
{
    int a = 100;
    int *p;

    p = &a;

    printf("Value = %d\n", *p);

    return 0;
}
