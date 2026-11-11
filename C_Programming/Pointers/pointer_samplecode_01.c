#include <stdio.h>

int main(void)
{
    int a = 10;
    int *ptr = &a;

    printf("Value of a = %d\n", a);
    printf("Address of a = %p\n", (void *)&a);
    printf("Value of ptr = %p\n", (void *)ptr);
    printf("Value of *ptr = %d\n", *ptr);

    *ptr = 20;

    printf("Updated value of a = %d\n", a);

    return 0;
}






/*


Value of a = 10
Address of a = 0x7ffd1234
Value of ptr = 0x7ffd1234
Value of *ptr = 10
Updated value of a = 20


*/
