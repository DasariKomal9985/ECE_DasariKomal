#include <stdio.h>
#include <string.h>

int main(void)
{
    char source[] = "Embedded";
    char destination[20];

    strncpy(destination, source, 5);
    destination[5] = '\0';

    printf("Destination = %s\n", destination);

    return 0;
}
