#include <stdio.h>

int main(void)
{
    int a = 10;

    a += 5;
    printf("+= : %d\n", a);

    a -= 3;
    printf("-= : %d\n", a);

    a *= 2;
    printf("*= : %d\n", a);

    a /= 4;
    printf("/= : %d\n", a);

    a %= 3;
    printf("%%= : %d\n", a);

    a &= 1;
    printf("&= : %d\n", a);

    a |= 2;
    printf("|= : %d\n", a);

    a ^= 3;
    printf("^= : %d\n", a);

    a <<= 1;
    printf("<<= : %d\n", a);

    a >>= 1;
    printf(">>= : %d\n", a);

    return 0;
}
