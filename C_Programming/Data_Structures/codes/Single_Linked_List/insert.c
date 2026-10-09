#include <stdio.h>
#include <stdlib.h>

// Define structure of node
struct room
{
    int id;            // Data part (stores value)
    struct room *next; // Pointer to the next node
};

// Declare global pointers
struct room *head = NULL, *newnode = NULL, *temp = NULL;

// Function to insert node at the end
void insert()
{
    int a;
    printf("enter number:\n");
    scanf("%d", &a); // Take user input

    // Allocate memory for new node
    newnode = (struct room *)malloc(sizeof(struct room));

    // Check memory allocation
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    // Assign values to node
    newnode->id = a;      // Set data
    newnode->next = NULL; // Set pointer to NULL (as it will be last node)

    // If list is empty
    if (head == NULL)
    {
        head = temp = newnode; // First node becomes head & temp
    }
    else
    {
        temp->next = newnode; // Link previous last node to new node
        temp = newnode;       // Move temp to new last node
    }
}

// Function to print all nodes
void traverse()
{
    struct room *temp1 = head; // Temporary pointer to traverse list

    // Loop until last node
    while (temp1 != NULL)
    {
        printf("%d\t", temp1->id); // Print data
        temp1 = temp1->next;       // Move to next node
    }
    printf("\n");
}

int main()
{
    int choice;

    while (1) // Infinite menu loop
    {
        printf("1.insert\n2.traverse\n3.exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert(); // Insert a new node
            break;
        case 2:
            traverse(); // Print linked list
            break;
        case 3:
            exit(0); // Terminate program
        default:
            printf("invalid choice:\n"); // Wrong input
        }
    }
    return 0;
}
