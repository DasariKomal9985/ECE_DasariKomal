#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p;

    p = malloc(sizeof(int));

    if(p == NULL)
        return 1;

    *p = 100;

    printf("Before free = %d\n", *p);

    free(p);

    printf("Pointer is now dangling\n");

    return 0;
}
