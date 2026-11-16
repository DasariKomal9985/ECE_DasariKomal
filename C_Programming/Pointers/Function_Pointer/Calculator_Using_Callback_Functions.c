Concept: The calculation function doesn't need to know which operation is being performed. It executes whichever function is passed to it.




#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int mul(int a, int b)
{
    return a * b;
}

void calculate(int a, int b, int (*callback)(int, int))
{
    printf("Result = %d\n", callback(a, b));
}

int main(void)
{
    int a, b, choice;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");

    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            calculate(a, b, add);
            break;

        case 2:
            calculate(a, b, sub);
            break;

        case 3:
            calculate(a, b, mul);
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}