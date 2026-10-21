
#include <stdio.h>

int main(void)
{
    int arr[] = {1, 2, 7, 6, 4, 5};
    int b = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;
    int largest = arr[0];

    for (int i = 0; i < b; i++)
    {
        sum += arr[i];

        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }

    int total = (largest * (largest + 1)) / 2; //n(n+1)/2

    printf("Largest number: %d\n", largest);
    printf("Array sum: %d\n", sum);
    printf("Missing element: %d\n", total - sum);

    return 0;
}

