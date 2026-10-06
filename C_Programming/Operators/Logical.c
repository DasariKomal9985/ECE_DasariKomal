#include <stdio.h>

int main(void)
{
    int a = 20;
    int b = 10;

    printf("AND = %d\n", a > 10 && b < 20);
    printf("OR  = %d\n", a < 10 || b < 20);
    printf("NOT = %d\n", !(a > b));

    return 0;
}
