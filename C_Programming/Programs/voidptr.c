#include <stdio.h>

int main()
{
    int a = 10;
    float b = 20.5;
    char c = 'A';

    void *ptr;

    ptr = &a;
    printf("Integer = %d\n", *(int *)ptr);

    ptr = &b;
    printf("Float = %.2f\n", *(float *)ptr);

    ptr = &c;
    printf("Character = %c\n", *(char *)ptr);

    return 0;
}