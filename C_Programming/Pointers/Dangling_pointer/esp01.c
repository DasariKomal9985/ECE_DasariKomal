#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p = malloc(sizeof(int));

    *p = 10;

    printf("Value = %d\n", *p);

    free(p);
    p = NULL;

    printf("Pointer is now NULL\n");

    return 0;
}
