#include <stdio.h>

int calculate(int a, int b)
{
    int result = a - b;
    return result;
}

int main(void)
{
    int x = 20;
    int y = 10;

    int answer = calculate(x, y);

    printf("Answer = %d\n", answer);

    return 0;
}
