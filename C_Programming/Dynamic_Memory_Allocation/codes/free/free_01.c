#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p;

    p = malloc(sizeof(int));

    if(p == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    *p = 100;

    printf("Value = %d\n", *p);

    free(p);
    p = NULL;

    printf("Memory released\n");

    return 0;
}
