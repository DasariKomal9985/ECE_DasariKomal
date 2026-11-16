Concept: A structure can hold multiple function pointers. This approach is useful in device driver operation tables.





#include <stdio.h>

struct Device
{
    void (*start)(void);
    void (*stop)(void);
};

void device_start(void)
{
    printf("Device Started\n");
}

void device_stop(void)
{
    printf("Device Stopped\n");
}

int main(void)
{
    struct Device d;

    d.start = device_start;
    d.stop = device_stop;

    d.start();
    d.stop();

    return 0;
}