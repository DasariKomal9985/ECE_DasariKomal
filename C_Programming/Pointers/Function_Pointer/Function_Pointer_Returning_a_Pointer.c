int *(*ptr)(void);


ptr is a function pointer.
The function accepts no arguments.
The function returns an int * (pointer to integer).
ptr() calls the function.
*result accesses the returned integer value.



#include <stdio.h>

int value = 100;

int *get_value(void)
{
    return &value;
}

int main(void)
{
    int *(*ptr)(void);

    ptr = get_value;

    int *result = ptr();

    printf("Value = %d\n", *result);

    return 0;
}