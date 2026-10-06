#include <stdio.h>

int main(void)
{
    int arr[3] = {10, 20, 30};

    int *p1 = &arr[0];
    int *p2 = &arr[2];

    if(p1 < p2)
        printf("p1 is before p2\n");
    else
        printf("p1 is not before p2\n");

    return 0;
}
