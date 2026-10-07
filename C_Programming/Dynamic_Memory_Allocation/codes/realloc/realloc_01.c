#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p;
    int *temp;

    p = malloc(3 * sizeof(int));

    if(p == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    p[0] = 10;
    p[1] = 20;
    p[2] = 30;

    printf("Before realloc:\n");

    for(int i = 0; i < 3; i++)
    {
        printf("%d ", p[i]);
    }

    temp = realloc(p, 5 * sizeof(int));

    if(temp == NULL)
    {
        printf("\nReallocation failed\n");
        free(p);
        return 1;
    }

    p = temp;

    p[3] = 40;
    p[4] = 50;

    printf("\nAfter realloc:\n");

    for(int i = 0; i < 5; i++)
    {
        printf("%d ", p[i]);
    }

    printf("\n");

    free(p);
    p = NULL;

    return 0;
}
