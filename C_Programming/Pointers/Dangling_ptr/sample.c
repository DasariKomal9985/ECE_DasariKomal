#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int*)malloc(sizeof(int));
    *ptr = 10;

    free(ptr);  // memory freed
    ptr = NULL; // avoid dangling pointer

    return 0;
}
