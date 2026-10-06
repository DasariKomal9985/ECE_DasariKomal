#include <stdio.h>

int main(void)
{
    int a = 10;
    int *p = &a;

    printf("Value = %d\n", *p);
    printf("Address = %p\n", (void *)p);

    return 0;
}
