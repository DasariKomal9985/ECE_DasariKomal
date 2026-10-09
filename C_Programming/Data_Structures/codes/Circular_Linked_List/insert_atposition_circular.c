#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
struct Node *tail = NULL;
struct Node *newNode = NULL;
struct Node *temp = NULL;
void insertatend()
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
void insertatposition()
{
   int pos, i = 1;
    newNode = malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!");
        return;
    }
    printf("\nEnter the position to insert the new node: ");
    scanf("%d", &pos);
    printf("Enter the value to be inserted: ");
    scanf("%d", &(newNode->data));
    newNode->next = NULL;
    if (tail == NULL)
    {
        tail = newNode;
        tail->next = newNode;
    }
    else
    {
        temp = tail->next;
        while ((i < pos - 1) && (temp != tail))
        {
            temp = temp->next;
            ++i;
        }
        newNode->next = temp->next;     
        temp->next = newNode;
        if (temp == tail)
        {
            tail = newNode;
        }
    }
}
int main()
{
    int choice;
    do
    {
        printf("1. Insert at End\n2. Insert at Position\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertatend();
            break;
        case 2:
            insertatposition();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 5);
    return 0;
}
