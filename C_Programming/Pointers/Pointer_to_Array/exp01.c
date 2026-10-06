#include <stdio.h>

int main(void)
{
    int arr[3] = {10, 20, 30};

    int (*p)[3] = &arr;

    printf("%d\n", (*p)[0]);
    printf("%d\n", (*p)[1]);
    printf("%d\n", (*p)[2]);

    return 0;
}
