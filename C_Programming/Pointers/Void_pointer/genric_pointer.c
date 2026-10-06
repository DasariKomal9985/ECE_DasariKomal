#include <stdio.h>

int main(void)
{
    int a = 10;
    float b = 3.14f;
    char c = 'A';

    void *p;

    p = &a;
    printf("Integer = %d\n", *(int *)p);

    p = &b;
    printf("Float = %.2f\n", *(float *)p);

    p = &c;
    printf("Character = %c\n", *(char *)p);

    return 0;
}
