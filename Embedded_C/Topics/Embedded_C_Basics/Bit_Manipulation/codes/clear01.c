#include <stdio.h>

int main(void)
{
    unsigned char value = 0xFF;

    value &= ~(1 << 3);

    printf("Value = 0x%02X\n", value);

    return 0;
}
