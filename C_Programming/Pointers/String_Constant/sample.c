#include <stdio.h>

int main() {
    const char *str = "Hello";  // stored in read-only memory

    printf("%s\n", str);
    // str[0] = 'X'; // Not allowed

    return 0;
}
