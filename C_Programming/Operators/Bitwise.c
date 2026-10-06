#include <stdio.h>

int main(void)
{
    unsigned int a = 12;
    unsigned int b = 5;

    printf("AND = %u\n", a & b);
    printf("OR  = %u\n", a | b);
    printf("XOR = %u\n", a ^ b);
    printf("NOT = %u\n", ~a);
    printf("Left Shift = %u\n", a << 1);
    printf("Right Shift = %u\n", a >> 1);

    return 0;
}
