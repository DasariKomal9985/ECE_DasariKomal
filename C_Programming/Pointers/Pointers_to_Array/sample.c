#include <stdio.h>

int main() {
    int arr[4] = {10, 20, 30, 40};

    int (*ptr)[4] = &arr; // pointer to array

    for(int i = 0; i < 4; i++)
        printf("%d ", (*ptr)[i]);

    return 0;
}
