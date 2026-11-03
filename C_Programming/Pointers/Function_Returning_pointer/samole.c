#include <stdio.h>

int* getValue() {
    static int x = 500;  // static so memory persists
    return &x;
}

int main() {
    int *p = getValue();
    printf("Returned value = %d\n", *p);
    return 0;
}
