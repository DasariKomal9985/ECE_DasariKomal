#include <stdio.h>

int main(void)
{
    int arr[] = {10, 20, 30, 40, 50};
    int key = 40;
    int n = sizeof(arr) / sizeof(arr[0]);

    int low = 0;
    int high = n - 1;
    int mid;
    int found = 0;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (arr[mid] == key)
        {
            printf("Element found at index %d\n", mid);
            found = 1;
            break;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (!found)
    {
        printf("Element not found\n");
    }

    return 0;
}
