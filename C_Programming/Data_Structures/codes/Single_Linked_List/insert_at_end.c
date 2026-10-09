#include <stdio.h>
#include <stdlib.h>

// Define structure of a node
struct Node
{
    int data;          // To store value
    struct Node *next; // Pointer to the next node
};

// Global pointers for linked list
struct Node *head = NULL, *temp = NULL, *newNode = NULL;

// Function to insert node at the end
void insertAtEnd()
{
    // Allocate memory for a new node
    newNode = (struct Node *)malloc(sizeof(struct Node));

    // Check if memory allocation failed
    if (newNode == NULL)
    {
        printf("Memory not allocated\n");
        return;
    }
    else
    {
        // Take value input from user
        printf("Enter the value to be inserted: ");
        scanf("%d", &(newNode->data));

        newNode->next = NULL; // New node will be last node, so next = NULL

        // Check if list is empty
        if (head == NULL)
        {
            head = newNode; // First node becomes head
        }
        else
        {
            temp = head; // Start from head to find last node

            // Traverse till last node
            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode; // Link last node to new node
        }
    }
}

// Function to display all nodes (traverse list)
void traverse()
{
    temp = head; // Start from head

    // Traverse until we reach NULL
    while (temp != NULL)
    {
        printf("%d ", temp->data); // Print node data
        temp = temp->next;         // Move to next node
    }
    printf("\n"); // New line after printing list
}

int main()
{
    int choice;

    // Menu driven program
    do
    {
        printf("1. Insert at end\n2. Traverse\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertAtEnd(); // Call insert function
            break;
        case 2:
            traverse(); // Display list
            break;
        case 3:
            exit(0); // Exit program
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}
