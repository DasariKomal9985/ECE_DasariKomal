#include <stdio.h>

int main(void)
{
    int arr[] = {10, 20, 30, 40, 50};
    int key = 30;
    int n = sizeof(arr) / sizeof(arr[0]);
    int found = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            printf("Element found at index %d\n", i);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Element not found\n");
    }

    return 0;
}
