Concept: The array index selects which function to execute.




Enter two numbers: 20 10
1. Addition
2. Subtraction
3. Multiplication
Enter choice: 1
Result = 30




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

int main(void)
{
    int a, b, choice;

    int (*ptr[3])(int, int) = {add, sub, mul};

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");

    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= 3)
        printf("Result = %d\n", ptr[choice - 1](a, b));
    else
        printf("Invalid choice\n");

    return 0;
}