#include <stdio.h>

int main() {
    int a = 10;
    void *vp = &a;   // can store any data type address

    printf("%d\n", *(int*)vp);
    return 0;
}
