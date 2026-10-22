
#include <stdio.h>

int main(void)
{
    int arr[10];
    int size;

    printf("Enter Size: ");
    scanf("%d", &size);

    if (size < 3 || size > 10)
    {
        printf("Enter a size between 3 and 10.\n");
        return 1;
    }

    printf("Enter Elements: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    int first = arr[0];
    int second = arr[0];
    int third = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > first)
        {
            third = second;
            second = first;
            first = arr[i];
        }
        else if (arr[i] > second && arr[i] < first)
        {
            third = second;
            second = arr[i];
        }
        else if (arr[i] > third && arr[i] < second)
        {
            third = arr[i];
        }
    }

    printf("First largest: %d\n", first);
    printf("Second largest: %d\n", second);
    printf("Third largest: %d\n", third);

    return 0;
}

