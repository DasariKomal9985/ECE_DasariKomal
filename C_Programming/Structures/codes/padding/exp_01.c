#include <stdio.h>

struct Example
{
    char a;
    int b;
    char c;
};

int main(void)
{
    struct Example s;

    printf("Size of char = %zu\n", sizeof(char));
    printf("Size of int = %zu\n", sizeof(int));
    printf("Size of structure = %zu\n", sizeof(s));

    return 0;
}
