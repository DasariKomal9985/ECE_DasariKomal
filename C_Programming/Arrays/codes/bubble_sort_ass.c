#include <stdio.h>

int main(void)
{
    int arr[5] = {50, 20, 40, 10, 30};
    int temp;

    for(int i = 0; i < 5 - 1; i++)
    {
        for(int j = 0; j < 5 - 1 - i; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for(int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
