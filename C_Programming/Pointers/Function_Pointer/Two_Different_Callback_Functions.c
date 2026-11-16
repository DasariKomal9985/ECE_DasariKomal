Concept: The same control() function can execute different callbacks.




#include <stdio.h>

void led_on(void)
{
    printf("LED ON\n");
}

void led_off(void)
{
    printf("LED OFF\n");
}

void control(void (*callback)(void))
{
    callback();
}

int main(void)
{
    control(led_on);

    control(led_off);

    return 0;
}