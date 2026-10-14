#include <stdio.h>

int main(void)
{
    unsigned char value = 0xAB;

    unsigned char high = (value >> 4) & 0x0F;
    unsigned char low = value & 0x0F;

    printf("High Nibble = 0x%X\n", high);
    printf("Low Nibble  = 0x%X\n", low);

    return 0;
}
