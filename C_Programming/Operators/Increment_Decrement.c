#include <stdio.h>

int main(void)
{
    int a = 10;

    printf("Initial = %d\n", a);

    printf("Pre-increment = %d\n", ++a);
    printf("Post-increment = %d\n", a++);

    printf("After increment = %d\n", a);

    printf("Pre-decrement = %d\n", --a);
    printf("Post-decrement = %d\n", a--);

    printf("After decrement = %d\n", a);

    return 0;
}
