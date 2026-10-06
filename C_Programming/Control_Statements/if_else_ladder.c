#include <stdio.h>

int main(void)
{
    int marks = 85;

    if (marks >= 90)
    {
        printf("Grade A+\n");
    }
    else if (marks >= 75)
    {
        printf("Grade A\n");
    }
    else if (marks >= 60)
    {
        printf("Grade B\n");
    }
    else if (marks >= 50)
    {
        printf("Grade C\n");
    }
    else
    {
        printf("Fail\n");
    }

    return 0;
}
