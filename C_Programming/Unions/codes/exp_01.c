#include <stdio.h>

union Data
{
    int i;
    float f;
    char c;
};

int main(void)
{
    // Initialization
    union Data d = {10};

    // Access
    printf("i = %d\n", d.i);

    // Assign and access
    d.f = 25.5;
    printf("f = %.2f\n", d.f);

    d.c = 'A';
    printf("c = %c\n", d.c);

    return 0;
}
