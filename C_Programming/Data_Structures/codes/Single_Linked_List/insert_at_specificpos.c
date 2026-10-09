#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node
{
    int data;          // Data field
    struct Node *next; // Pointer to next node
};

// Global pointers
struct Node *head = NULL, *temp = NULL, *newNode = NULL, *temp1 = NULL, *temp2 = NULL;

// Insert node at the beginning
void insertAtBeginning()
{
    newNode = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory for node

    if (newNode == NULL) // Memory allocation check
    {
        printf("Memory not allocated\n");
        return;
    }
    else
    {
        printf("Enter the value to be inserted: ");
        scanf("%d", &(newNode->data)); // Read value
        newNode->next = head;          // Point new node to current head
        head = newNode;                // Make new node the head
    }
}

// Insert node at the end
void insertAtEnd()
{
    newNode = (struct Node *)malloc(sizeof(struct Node)); // Allocate node

    if (newNode == NULL) // Memory check
    {
        printf("Memory not allocated\n");
        return;
    }
    else
    {
        printf("Enter the value to be inserted: ");
        scanf("%d", &(newNode->data)); // Take value
        newNode->next = NULL;          // Last node points to NULL

        if (head == NULL) // If list empty
        {
            head = newNode; // First node becomes head
        }
        else
        {
            temp1 = head; // Start from head

            while (temp1->next != NULL) // Traverse to last node
            {
                temp1 = temp1->next;
            }

            temp1->next = newNode; // Link last node to new node
        }
    }
}

// Display the linked list
void traverse()
{
    temp2 = head; // Start temp2 from head

    while (temp2 != NULL) // Traverse till last node
    {
        printf("%d ", temp2->data); // Print data
        temp2 = temp2->next;        // Move to next
    }
    printf("\n"); // New line after print
}

// Insert at specific position
void insertAtSpecificPos()
{
    int pos, i = 1, count = 0;

    printf("Enter the position where you want to insert: ");
    scanf("%d", &pos); // Input position

    newNode = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory

    if (newNode == NULL) // Memory check
    {
        printf("Memory not allocated\n");
        return;
    }

    // Count total nodes
    temp = head;
    while (temp != NULL)
    {
        count++; // Count nodes
        temp = temp->next;
    }

    // Check valid position
    if (pos > count + 1 || pos < 1)
    {
        printf("Position out of range\n");
        return;
    }

    temp = head; // Reset temp to head

    // Move temp to (pos-1)th node
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }

    printf("Enter the value to be inserted: ");
    scanf("%d", &(newNode->data)); // Input value

    newNode->next = temp->next; // Set newNode next pointer
    temp->next = newNode;       // Link previous node to new node
}

int main()
{
    int choice;

    // Menu options
    printf("1. Insert at specific position\n2. Insert at end\n3. Insert at beginning\n4. Traverse\n5. Exit\n");

    do
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertAtBeginning(); // Insert at beginning
            break;
        case 2:
            insertAtEnd(); // Insert at end
            break;
        case 3:
            insertAtSpecificPos(); // Insert at specific position
            break;
        case 4:
            traverse(); // Display list
            break;
        case 5:
            exit(0); // Exit program
            break;
        default:
            printf("Invalid choice\n"); // Invalid input
        }

    } while (choice != 6); // Loop until user exits

    return 0;
}
