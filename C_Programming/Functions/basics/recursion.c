#include <stdio.h>

int factorial(int n)
{
    if (n == 0)
        return 1;

    return n * factorial(n - 1);
}

int main(void)
{
    int result = factorial(5);

    printf("Factorial = %d\n", result);

    return 0;
}


/*
factorial(5)
 ↓
5 × factorial(4)
 ↓
5 × 4 × factorial(3)
 ↓
5 × 4 × 3 × factorial(2)
 ↓
5 × 4 × 3 × 2 × factorial(1)
 ↓
120
*/
