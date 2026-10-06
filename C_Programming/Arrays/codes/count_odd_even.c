#include <stdio.h>

int main(void)
{
    int arr[6] = {10, 15, 22, 33, 40, 51};
    int even = 0;
    int odd = 0;

    for(int i = 0; i < 6; i++)
    {
        if(arr[i] % 2 == 0)
            even++;
        else
            odd++;
    }

    printf("Even = %d\n", even);
    printf("Odd = %d\n", odd);

    return 0;
}
