#include <stdio.h>

void fun(int x) {
    printf("Value: %d\n", x);
}

int main() {
    void (*fp)(int);  // function pointer declaration
    fp = fun;

    fp(100);
    return 0;
}
