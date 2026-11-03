#include <stdio.h>

void modify(int x) {
    x = 50;
}

int main() {
    int a = 10;
    modify(a);
    printf("a = %d\n", a); // unchanged
    return 0;
}
