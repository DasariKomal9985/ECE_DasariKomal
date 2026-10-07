#include <stdio.h>

enum Status
{
    OFF,
    ON,
    ERROR
};

int main(void)
{
    enum Status device;

    device = ON;

    printf("OFF = %d\n", OFF);
    printf("ON = %d\n", ON);
    printf("ERROR = %d\n", ERROR);

    printf("Device Status = %d\n", device);

    return 0;
}
