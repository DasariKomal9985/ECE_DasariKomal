#include <stdio.h>

int main(void)
{
    unsigned int value = 0x12345678;
    unsigned char *p = (unsigned char *)&value;

    printf("Byte 0 = 0x%02X\n", p[0]);
    printf("Byte 1 = 0x%02X\n", p[1]);
    printf("Byte 2 = 0x%02X\n", p[2]);
    printf("Byte 3 = 0x%02X\n", p[3]);

    return 0;
}
