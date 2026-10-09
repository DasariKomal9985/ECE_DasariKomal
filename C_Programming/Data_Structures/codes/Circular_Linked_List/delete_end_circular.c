#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
struct Node *tail = NULL;
struct Node *temp = NULL;
struct Node *newNode = NULL;
struct Node *current = NULL;
struct Node *prevnode = NULL;
void deleteatend()
{
    current = tail->next;
    if (tail == NULL)
    {
        printf("\nThe list is empty! Deletion not possible.");
        return;
    }
    else if (current->next == tail->next) // only one node
    {
        printf("\nThe deleted element is: %d", tail->data);
        free(tail);
        head = NULL;
        tail = NULL;
    }  
    else
    {
        while (current->next != tail->next)
        {
            prevnode = current;
            current = current->next;
        }
        printf("\nThe deleted element is: %d", tail->data);
        prevnode->next = tail->next;
        tail = prevnode;
        free(current);
    }
}
void insert()
{
    newNode = malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!");
        return;
    }
    printf("\nEnter the value to be inserted: ");
    scanf("%d", &(newNode->data));
    newNode->next = NULL;
    temp = head;
    if (tail == NULL)
    {
        tail = newNode;
        tail->next = newNode;
    }
    else
    {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}
void display()
{
    if (tail == NULL)
    {
        printf("\nThe list is empty!");
        return;
    }
    temp = tail->next; // head
    printf("\nThe elements of the linked list are:\n");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);

    printf("\nHead = %d", tail->next->data);
    printf("\nTail = %d", tail->data);
    printf("\nTail->next = %d (Head)", tail->next->data);
    printf("\n");
}

int main()
{
    int choice;
    do
    {
        printf("\n1. Insert at end\n2. Display\n3. deleteatend\n4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            deleteatend();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nInvalid choice! Please try again.");
            break;
        }
    } while (choice != 5);
    return 0;
}
