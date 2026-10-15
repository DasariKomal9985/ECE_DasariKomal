#include <stdio.h>

int main(void)
{
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);

    if (a >= b && a >= c)
        printf("%d is biggest\n", a);
    else if (b >= a && b >= c)
        printf("%d is biggest\n", b);
    else
        printf("%d is biggest\n", c);

    return 0;
}
