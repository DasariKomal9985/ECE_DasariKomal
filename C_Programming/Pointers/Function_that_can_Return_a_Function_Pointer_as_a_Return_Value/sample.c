#include <stdio.h>

void hello() {
    printf("Hello World!\n");
}

// Function that returns a function pointer
void (*getFunction())() {
    return hello;
}

int main() {
    void (*fp)() = getFunction();
    fp(); // call returned function
    return 0;
}
