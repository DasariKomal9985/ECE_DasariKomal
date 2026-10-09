#include <stdio.h>

int main(void)
{
    long long n, temp, sum = 0, power;
    int digits = 0, digit, i;

    printf("Enter a nonnegative number: ");
    scanf("%lld", &n);

    if (n < 0)
    {
        printf("Not an Armstrong number\n");
        return 0;
    }

    temp = n;

    do
    {
        digits++;
        temp = temp / 10;
    } while (temp != 0);

    temp = n;

    do
    {
        digit = temp % 10;
        power = 1;

        for (i = 0; i < digits; i++)
            power = power * digit;

        sum = sum + power;
        temp = temp / 10;
    } while (temp != 0);

    if (sum == n)
        printf("Armstrong number\n");
    else
        printf("Not an Armstrong number\n");

    return 0;
}



//Example: 153 → \(1^3+5^3+3^3=153\), so it is an Armstrong number.
