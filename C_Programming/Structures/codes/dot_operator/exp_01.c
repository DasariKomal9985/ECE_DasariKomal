#include <stdio.h>

struct Student
{
    int roll;
    float marks;
};

int main(void)
{
    struct Student s;

    s.roll = 101;
    s.marks = 85.5;

    printf("Roll = %d\n", s.roll);
    printf("Marks = %.2f\n", s.marks);

    return 0;
}
