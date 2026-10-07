#include <stdio.h>

struct Student
{
    int roll;
    float marks;
};

int main(void)
{
    struct Student s;
    struct Student *p = &s;

    p->roll = 101;
    p->marks = 90.5;

    printf("Roll = %d\n", p->roll);
    printf("Marks = %.2f\n", p->marks);

    return 0;
}
