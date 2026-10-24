#include <stdio.h>

int sum(int arr[], int size)
{
    if (size == 0)
    {
        return 0;
    }

    return arr[size - 1] + sum(arr, size - 1);
}

int main()
{
    int arr[100];
    int size, result;

    printf("Enter size: ");
    scanf("%d", &size);

    printf("Enter elements: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    result = sum(arr, size);

    printf("Sum = %d\n", result);

    return 0;
}



/*

10 20 30 40 50


sum(arr, 5)
= 50 + sum(arr, 4)
= 50 + 40 + sum(arr, 3)
= 50 + 40 + 30 + sum(arr, 2)
= 50 + 40 + 30 + 20 + sum(arr, 1)
= 50 + 40 + 30 + 20 + 10 + sum(arr, 0)
= 150


*/
