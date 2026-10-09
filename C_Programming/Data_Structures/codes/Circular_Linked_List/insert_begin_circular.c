#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL, *tail = NULL;

void insertcircularatbeginning()
{
    struct Node *newNode = malloc(sizeof(struct Node));

    if (!newNode)
    {
        printf("Memory not allocated!\n");
        return;
    }

    printf("Enter number: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    // If list empty
    if (head == NULL)
    {
        head = tail = newNode;
        tail->next = head; // circular link
    }
    else
    {
        newNode->next = head; // new node -> old head
        head = newNode;       // head updated
        tail->next = head;    // tail points to new head
    }
}

void traverse()
{
    if (head == NULL) 
    {
        printf("List is empty\n");
        return;
    }

    struct Node *temp = head;

    printf("\nList: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    // Display head, tail, tail->next
    printf("\nHead = %d", head->data);
    printf("\nTail = %d", tail->data);
    printf("\nTail->next = %d (Head)\n", tail->next->data);
}

int main()
{
    int choice;

    do
    {
        printf("\n1. Insert at Beginning\n2. Traverse\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertcircularatbeginning();
            break;
        case 2:
            traverse();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice\n");
        }

    } while (choice != 3);

    return 0;
}
