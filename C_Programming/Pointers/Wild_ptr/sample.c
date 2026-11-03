#include <stdio.h>

int main() {
    int *ptr;   // wild pointer (contains garbage address)

    ptr = NULL; // fix wild pointer
    return 0;
}
