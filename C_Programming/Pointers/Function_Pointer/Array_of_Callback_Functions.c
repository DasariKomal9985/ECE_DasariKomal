Concept: An array stores multiple callback function addresses.


#include <stdio.h>

void led_on(void)
{
    printf("LED ON\n");
}

void led_off(void)
{
    printf("LED OFF\n");
}

void buzzer_on(void)
{
    printf("Buzzer ON\n");
}

int main(void)
{
    void (*callback[3])(void) = {
        led_on,
        led_off,
        buzzer_on
    };

    callback[0]();
    callback[1]();
    callback[2]();

    return 0;
}