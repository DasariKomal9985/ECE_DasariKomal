#include <stdio.h>
#include <string.h>

int main(void)
{
    char source[] = "Embedded";
    char destination[20];

    strcpy(destination, source);

    printf("Source = %s\n", source);
    printf("Destination = %s\n", destination);

    return 0;
}
