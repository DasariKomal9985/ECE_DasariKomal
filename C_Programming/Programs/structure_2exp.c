#include <stdio.h>

struct Employee
{
    int id;
    float salary;
};

int main()
{
    struct Employee e;

    printf("Enter employee ID: ");
    scanf("%d", &e.id);

    printf("Enter salary: ");
    scanf("%f", &e.salary);

    printf("\nEmployee Details\n");
    printf("ID = %d\n", e.id);
    printf("Salary = %.2f\n", e.salary);

    return 0;
}