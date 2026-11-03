#include <stdio.h>

int main() {
    int x = 10, y = 20;
    int * const ptr = &x;

    *ptr = 50;   // allowed
    // ptr = &y; // NOT allowed

    printf("%d\n", *ptr);
    return 0;
}
