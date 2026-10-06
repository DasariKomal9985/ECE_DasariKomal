#include <stdio.h>

int main(void)
{
    int a = 10;
    int b = 20;
    int c = 30;

    int *p[3] = {&a, &b, &c};

    printf("%d\n", *p[0]);
    printf("%d\n", *p[1]);
    printf("%d\n", *p[2]);

    return 0;
}
