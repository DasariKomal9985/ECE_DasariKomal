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

    struct Student *ptr = &s;

    printf("Using Dot Operator\n");
    printf("Roll  = %d\n", s.roll);
    printf("Name  = %s\n", s.name);
    printf("Marks = %.2f\n", s.marks);

    printf("\nUsing Arrow Operator\n");
    printf("Roll  = %d\n", ptr->roll);
    printf("Name  = %s\n", ptr->name);
    printf("Marks = %.2f\n", ptr->marks);

    return 0;
}




Using Dot Operator
Roll  = 101
Name  = Komal
Marks = 85.50

Using Arrow Operator
Roll  = 101
Name  = Komal
Marks = 85.50