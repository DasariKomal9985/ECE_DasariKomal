#include <stdio.h>

struct Status
{
    unsigned int ready : 1;
    unsigned int error : 1;
    unsigned int mode  : 2;
};

int main(void)
{
    struct Status s;

    s.ready = 1;
    s.error = 0;
    s.mode = 3;

    printf("Ready = %u\n", s.ready);
    printf("Error = %u\n", s.error);
    printf("Mode = %u\n", s.mode);

    return 0;
}
