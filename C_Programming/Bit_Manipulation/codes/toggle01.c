#include <stdio.h>

int main(void)
{
    unsigned char value = 0x08;

    value ^= (1 << 3);

    printf("Value = 0x%02X\n", value);

    return 0;
}
