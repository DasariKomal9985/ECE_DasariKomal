#include <stdio.h>

int main(void)
{
    int arr[5] = {10, 20, 30, 40, 50};
    int key = 30;
    int found = 0;

    for(int i = 0; i < 5; i++)
    {
        if(arr[i] == key)
        {
            printf("Element found at index %d\n", i);
            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("Element not found\n");
    }

    return 0;
}
