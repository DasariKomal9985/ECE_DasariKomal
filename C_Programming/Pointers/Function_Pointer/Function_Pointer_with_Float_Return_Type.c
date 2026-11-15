Concept: Function pointers can point to functions returning float, int, void, etc.





#include <stdio.h>

float calculate(float a, float b)
{
    return a * b;
}

int main(void)
{
    float (*ptr)(float, float);

    ptr = calculate;

    printf("Result = %.2f\n", ptr(5.5, 2.0));

    return 0;
}