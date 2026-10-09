#include <stdio.h>

int main(void)
{
    int n, original, reverse = 0, digit;

    printf("Enter a nonnegative number: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Not a palindrome\n");
        return 0;
    }

    original = n;

    while (n != 0)
    {
        digit = n % 10;
        reverse = reverse * 10 + digit;
        n = n / 10;
    }

    if (original == reverse)
        printf("Palindrome number\n");
    else
        printf("Not a palindrome\n");

    return 0;
}




//Example: 121 is a palindrome; 123 is not. The number 0 is also a palindrome.
