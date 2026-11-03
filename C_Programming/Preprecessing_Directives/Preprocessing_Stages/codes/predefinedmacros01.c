#include <stdio.h>

int main(void)
{
    printf("File = %s\n", __FILE__);
    printf("Line = %d\n", __LINE__);
    printf("Date = %s\n", __DATE__);
    printf("Time = %s\n", __TIME__);

    return 0;
}
