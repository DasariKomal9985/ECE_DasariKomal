#include <stdio.h>

int main(void)
{
    int a = 10;
    int *p = &a;

    printf("Value = %d\n", *p);

    *p = 50;

    printf("Updated Value = %d\n", a);

    return 0;
}
