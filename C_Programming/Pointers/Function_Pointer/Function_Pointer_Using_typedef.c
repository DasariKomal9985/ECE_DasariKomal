FuncPtr becomes an alternative name for the function pointer type.


typedef int (*FuncPtr)(int, int);



#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

typedef int (*FuncPtr)(int, int);

int main(void)
{
    FuncPtr ptr;

    ptr = add;

    printf("Sum = %d\n", ptr(10, 20));

    return 0;
}