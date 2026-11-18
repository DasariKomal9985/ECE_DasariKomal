
#include <stdio.h>

int sum_array(int *arr, int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum = sum + arr[i];
    }

    return sum;
}

void update_value(int *ptr, int value)
{
    *ptr = value;
}

int add(int a, int b)
{
    return a + b;
}

int main(void)
{
    int arr[5] = {10, 20, 30, 40, 50};

    int *ptr = arr;

    int total;

    printf("Array Elements:\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    total = sum_array(arr, 5);

    printf("Array Sum = %d\n", total);

    update_value(ptr + 2, 100);

    printf("Updated Array[2] = %d\n", arr[2]);

    int (*func_ptr)(int, int) = add;

    int result = func_ptr(10, 20);

    printf("Function Pointer Result = %d\n", result);

    return 0;
}
