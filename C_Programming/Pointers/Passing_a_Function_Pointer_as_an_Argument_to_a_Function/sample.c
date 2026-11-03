#include <stdio.h>

void greet() {
    printf("Hello!\n");
}

void callFunction(void (*fp)()) {
    fp();
}

int main() {
    callFunction(greet);
    return 0;
}
