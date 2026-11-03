#include <stdio.h>

void fun1() { printf("Function 1\n"); }
void fun2() { printf("Function 2\n"); }
void fun3() { printf("Function 3\n"); }

int main() {
    void (*fp[3])() = { fun1, fun2, fun3 };  // array of function pointers

    for (int i = 0; i < 3; i++)
        fp[i]();

    return 0;
}
