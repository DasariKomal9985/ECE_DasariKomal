#include <stdio.h>

int main(void)
{
    printf("Start\n");

    goto end;

    printf("This will not execute\n");

end:
    printf("End\n");

    return 0;
}
