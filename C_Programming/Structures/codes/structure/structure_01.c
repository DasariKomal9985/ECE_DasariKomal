#include <stdio.h>

struct Student
{
    int roll;
    char name[20];
    float marks;
};

int main(void)
{
    struct Student s = {101, "Komal", 85.5};

    printf("Roll = %d\n", s.roll);
    printf("Name = %s\n", s.name);
    printf("Marks = %.2f\n", s.marks);

    return 0;
}
