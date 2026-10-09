#include <stdio.h>
#include <stdlib.h>

// Define structure of a node
struct Node
{
    int data;          // To store value
    struct Node *next; // Pointer to the next node
};

// Global pointers for linked list
struct Node *head = NULL, *temp = NULL, *newNode = NULL, *temp1 = NULL;

// Function to insert node at the end
void insertAtCircularList()
{
    newNode = malloc(sizeof(struct Node)); // Allocate memory for new node
    printf("Enter number: ");
    scanf("%d", &newNode->data); // Read data for new node
    if (head == NULL)            // If list is empty
    {
        head = temp = newNode; // Set head and tail to new nod
    }
    else // If list has elements already
    {
        temp->next = newNode; // Link new node at the end
        temp = newNode;       // Update tail to new node
    }
    temp->next = head; // Make last node point back to first node
}

// Function to display all nodes (traverse list)
void traverse()
{
    temp1 = head; // Start from head
    // Traverse until we reach head again
    do
    {
        printf("%d ", temp1->data); // Print node data
        temp1 = temp1->next;        // Move to next node
    } while (temp1 != head);
    printf("Head ");
    printf("%d ", temp1->data); // Print last node data
    printf("\n"); // New line after printing list
}

int main()
{
    int choice;

    // Menu driven program
    do
    {
        printf("1. insertAtCircularList\n2. Traverse\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertAtCircularList(); // Call insert function
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
