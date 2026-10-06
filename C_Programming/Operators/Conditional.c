#include <stdio.h>

int main(void)
{
    int a = 20;
    int b = 10;

    int largest = (a > b) ? a : b;

    printf("Largest = %d\n", largest);

    return 0;
}
