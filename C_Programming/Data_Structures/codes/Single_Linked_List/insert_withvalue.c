#include <stdio.h>
#include <stdlib.h>

// Define structure of node
struct room
{
    int id;            // Data part (stores value)
    struct room *next; // Pointer to next node
};

// Function to create a new node
struct room *createNode(int value)
{
    // Allocate memory for new node using malloc
    struct room *newnode = (struct room *)malloc(sizeof(struct room));

    // Check if memory allocated successfully
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL; // return null if memory is not allocated
    }

    newnode->id = value;  // Assign value to node's data field
    newnode->next = NULL; // Set next pointer to NULL (because it's a new last node)

    return newnode; // Return pointer to newly created node
}

// Function to insert node at end of linked list
struct room *insertNode(struct room *head, int value)
{
    // Create a node with given value
    struct room *newnode = createNode(value);

    // If memory allocation failed
    if (newnode == NULL)
        return head; // Return existing list unchanged

    // If list is empty, new node becomes head
    if (head == NULL)
        return newnode; // New node is now the first node

    // Otherwise, traverse list to find last node
    struct room *temp = head;
    while (temp->next != NULL) // Move until last node
    {
        temp = temp->next;
    }

    temp->next = newnode; // Link last node to new node

    return head; // Return head (unchanged)
}

// Function to print all elements in the list
void traverseList(struct room *head)
{
    // If list is empty
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    // Pointer to traverse list
    struct room *temp = head;

    // Print until last node
    while (temp != NULL)
    {
        printf("%d\t", temp->id); // Print node value
        temp = temp->next;        // Move to next node
    }
    printf("\n");
}

int main()
{
    struct room *head = NULL; // Initially list is empty
    int choice, value;

    while (1) // Infinite loop for menu
    {
        // Display options
        printf("\n1. Insert\n2. Traverse\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Input value from user
            printf("Enter number: ");
            scanf("%d", &value);

            // Insert node and update head
            head = insertNode(head, value);
            break;

        case 2:
            // Display all nodes
            traverseList(head);
            break;

        case 3:
            exit(0); // Close program

        default:
            printf("Invalid choice\n"); // Wrong menu option
        }
    }
    return 0;
}
