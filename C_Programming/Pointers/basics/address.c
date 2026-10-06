#include <stdio.h>

int main(void)
{
    int a = 10;

    printf("Value = %d\n", a);
    printf("Address = %p\n", (void *)&a);

    return 0;
}
