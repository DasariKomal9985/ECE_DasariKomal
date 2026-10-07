#include <stdio.h>

void add(int *restrict a, int *restrict b)
{
    *a = *a + *b;
}

int main(void)
{
    int x = 10;
    int y = 20;

    add(&x, &y);

    printf("x = %d\n", x);

    return 0;
}
