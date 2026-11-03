#include <stdio.h>

int main() {
    int a = 10, b = 20;
    int * const ptr = &a; // constant pointer

    *ptr = 50;   // allowed
    // ptr = &b; // NOT allowed

    printf("%d\n", *ptr);
}
