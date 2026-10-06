#include <stdio.h>

int main(void)
{
    int arr[5] = {10, 20, 30, 40, 50};
    int key = 40;
    int low = 0;
    int high = 4;
    int mid;
    int found = 0;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(arr[mid] == key)
        {
            printf("Element found at index %d\n", mid);
            found = 1;
            break;
        }
        else if(key > arr[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if(found == 0)
    {
        printf("Element not found\n");
    }

    return 0;
}
