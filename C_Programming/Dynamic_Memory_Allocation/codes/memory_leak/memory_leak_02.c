#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p;

    p = malloc(5 * sizeof(int));

    if(p == NULL)
    {
        return 1;
    }

    p[0] = 10;

    printf("Value = %d\n", p[0]);

    free(p);
    p = NULL;

    return 0;
}
