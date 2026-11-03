#include <stdio.h>

int main() {
    char *names[] = {"Komal", "Rohit", "Anita", "Sam"};

    for (int i = 0; i < 4; i++)
        printf("%s\n", names[i]);

    return 0;
}
