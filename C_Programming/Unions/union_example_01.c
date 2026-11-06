#include <stdio.h>
#include <string.h>

union Data
{
    int number;
    float value;
    char name[20];
};

int main(void)
{
    union Data d = {.number = 100};

    printf("Integer Value = %d\n", d.number);

    d.value = 25.5;

    printf("Float Value = %.2f\n", d.value);

    strcpy(d.name, "Komal");

    printf("String Value = %s\n", d.name);

    printf("Union Size = %zu bytes\n", sizeof(d));

    return 0;
}




Integer Value = 100
Float Value = 25.50
String Value = Komal
Union Size = 20 bytes


The 20-byte size is typical on systems where int and float are 4 bytes and the union has 4-byte alignment. Actual size is implementation-dependent.
