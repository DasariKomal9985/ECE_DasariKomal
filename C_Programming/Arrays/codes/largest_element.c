#include <stdio.h>

int main(void)
{
    int arr[5] = {25, 10, 50, 30, 40};
    int largest = arr[0];

    for(int i = 1; i < 5; i++)
    {
        if(arr[i] > largest)
        {
            largest = arr[i];
        }
    }

    printf("Largest = %d\n", largest);

    return 0;
}
