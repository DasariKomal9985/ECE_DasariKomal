#include <stdio.h>
#include <stdlib.h>

int global_init = 100;
int global_zero;
static int static_init = 200;
static int static_zero;

int main(void)
{
    int local = 10;
    int *ptr = malloc(sizeof(int));

    if (ptr == NULL)
    {
        return 1;
    }

    *ptr = 50;

    printf("Global initialized: %d\n", global_init);
    printf("Global zero: %d\n", global_zero);
    printf("Static initialized: %d\n", static_init);
    printf("Static zero: %d\n", static_zero);
    printf("Local variable: %d\n", local);
    printf("Heap allocated value: %d\n", *ptr);

    free(ptr);
    ptr = NULL;

    return 0;
}
