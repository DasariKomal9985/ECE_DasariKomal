#include <stdio.h>

int main(void)
{
    int arr[5] = {10, 20, 30, 40, 50};
    int sum = 0;
    float average;

    for(int i = 0; i < 5; i++)
    {
        sum = sum + arr[i];
    }

    average = (float)sum / 5;

    printf("Average = %.2f\n", average);

    return 0;
}
