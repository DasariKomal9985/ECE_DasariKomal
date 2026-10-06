#include <stdio.h>

int main(void)
{
    int a = 10;
    void *p = &a;

    printf("Value = %d\n", *(int *)p);

    return 0;
}
