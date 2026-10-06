#include <stdio.h>

int main(void)
{
    int arr[3] = {10, 20, 30};
    int *p = arr;

    printf("%d\n", *p);

    p++;
    printf("%d\n", *p);

    p++;
    printf("%d\n", *p);

    return 0;
}
