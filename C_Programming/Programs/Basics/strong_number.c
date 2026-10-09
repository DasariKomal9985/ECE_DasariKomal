#include <stdio.h>

int main(void)
{
    int n, temp, digit, i;
    int factorial, sum = 0;

    printf("Enter a nonnegative number: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Not a strong number\n");
        return 0;
    }

    temp = n;

    do
    {
        digit = temp % 10;
        factorial = 1;

        for (i = 1; i <= digit; i++)
            factorial = factorial * i;

        sum = sum + factorial;
        temp = temp / 10;
    } while (temp != 0);

    if (sum == n)
        printf("Strong number\n");
    else
        printf("Not a strong number\n");

    return 0;
}





//Example: 145 → \(1!+4!+5!=1+24+120=145\), so it is a strong number.
