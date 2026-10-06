#include <stdio.h>

int main(void)
{
    int arr[5] = {25, 10, 50, 30, 40};
    int smallest = arr[0];

    for(int i = 1; i < 5; i++)
    {
        if(arr[i] < smallest)
        {
            smallest = arr[i];
        }
    }

    printf("Smallest = %d\n", smallest);

    return 0;
}
