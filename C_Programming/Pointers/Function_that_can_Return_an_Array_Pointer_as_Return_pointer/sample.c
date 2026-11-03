#include <stdio.h>

int (*getArray())[5] {
    static int arr[5] = {1, 2, 3, 4, 5};
    return &arr;
}

int main() {
    int (*ptr)[5] = getArray();

    for(int i = 0; i < 5; i++)
        printf("%d ", (*ptr)[i]);
}
