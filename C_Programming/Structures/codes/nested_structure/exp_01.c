#include <stdio.h>

struct Address
{
    char city[20];
    int pincode;
};

struct Student
{
    int roll;
    char name[20];
    struct Address address;
};

int main(void)
{
    struct Student s =
    {
        101,
        "Komal",
        {"Chennai", 600001}
    };

    printf("Roll = %d\n", s.roll);
    printf("Name = %s\n", s.name);
    printf("City = %s\n", s.address.city);
    printf("Pincode = %d\n", s.address.pincode);

    return 0;
}
