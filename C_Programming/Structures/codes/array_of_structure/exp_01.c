#include <stdio.h>

struct Student
{
    int roll;
    char name[20];
    float marks;
};

int main(void)
{
    struct Student s[3] =
    {
        {101, "Komal", 85.5},
        {102, "Ravi", 90.0},
        {103, "Arun", 78.5}
    };

    for(int i = 0; i < 3; i++)
    {
        printf("Roll = %d\n", s[i].roll);
        printf("Name = %s\n", s[i].name);
        printf("Marks = %.2f\n\n", s[i].marks);
    }

    return 0;
}
