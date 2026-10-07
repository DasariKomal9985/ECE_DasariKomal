#include <stdio.h>

extern int value;

void display(void);

int main(void)
{
    printf("Value = %d\n", value);

    value = 200;

    display();

    return 0;
}
