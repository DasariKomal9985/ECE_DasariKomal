#include <stdio.h>

#define CREATE_VAR(a, b) a##b

int main(void)
{
    int value1 = 100;

    printf("%d\n", CREATE_VAR(value, 1));

    return 0;
}
