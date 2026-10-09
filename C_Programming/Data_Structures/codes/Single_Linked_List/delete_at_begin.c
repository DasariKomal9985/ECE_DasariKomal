#include <stdio.h>
#include <stdlib.h>

// Node structure for singly linked list
struct Node
{
    int data;          // stores data
    struct Node *next; // pointer to next node
};

// Global pointers
struct Node *head = NULL, *temp = NULL, *newNode = NULL;

// Delete node from beginning
void deleteAtBegin()
{
    if (head == NULL) // If list is empty
    {
        printf("List is empty, nothing to delete\n");
        return;
    }
    else
    {
        temp = head;                                 // Store current head in temp
        head = head->next;                           // Move head to next node
        printf("Deleted element: %d\n", temp->data); // Show deleted data
        free(temp);                                  // Free memory of old head
    }
}

// Insert node at beginning
void insertAtBegin()
{
    newNode = (struct Node *)malloc(sizeof(struct Node)); // Allocate memory

    if (newNode == NULL) // Check memory allocation
    {
        printf("Memory not allocated\n");
        return;
    }
    else
    {
        printf("Enter the value to be inserted: ");
        scanf("%d", &(newNode->data)); // Input value

        newNode->next = head; // Point new node to old head
        head = newNode;       // Make new node the head
    }
}

// Traverse and display list
void traverse()
{
    if (head == NULL) // If list empty
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        temp = head; // Start from head
        printf("The elements in the list are: ");

        while (temp != NULL) // Traverse till NULL
        {
            printf("%d ", temp->data); // Print data
            temp = temp->next;         // Move to next node
        }

        printf("\n");
    }
}

int main()
{
    int choise;

    do
    {
        // Menu options
        printf("1. Insert at begin\n2. Delete at begin\n3. Traverse\n4. Exit\n");
        printf("Enter your choise: ");
        scanf("%d", &choise);

        switch (choise)
        {
        case 1:
            insertAtBegin(); // Call insertion function
            break;
        case 2:
            deleteAtBegin(); // Call delete function
            break;
        case 3:
            traverse(); // Call display function
            break;
        case 4:
            exit(0); // Exit program
            break;
        default:
            printf("Invalid choise\n");
            break;
        }

    } while (choise != 5); // Loop menu (5 is dummy condition)

    return 0;
}
