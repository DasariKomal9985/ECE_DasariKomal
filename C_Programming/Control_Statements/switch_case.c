#include <stdio.h>

int main(void)
{
    int choice = 2;

    switch (choice)
    {
        case 1:
            printf("Start\n");
            break;

        case 2:
            printf("Stop\n");
            break;

        case 3:
            printf("Reset\n");
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}
