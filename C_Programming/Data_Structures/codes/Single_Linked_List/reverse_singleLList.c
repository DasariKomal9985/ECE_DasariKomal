#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL, *temp = NULL, *newNode = NULL;
void reverse()
{
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = head;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (next != NULL)
    {
        next = next->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    printf("Linked list reversed\n");
}
void insertAtBegin()
{
    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory not allocated\n");
        return;
    }
    else
    {
        printf("Enter the value to be inserted: ");
        scanf("%d", &(newNode->data));
        newNode->next = head;
        head = newNode;
    }
}
void traverse()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        temp = head;
        printf("The elements in the list are: ");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main()
{
    int choise;
    do
    {
        printf("1. Insert at begin\n2. Traverse\n3. Reverse\n4. Exit\n");
        printf("Enter your choise: ");
        scanf("%d", &choise);
        switch (choise)
        {
        case 1:
            insertAtBegin();
            break;
        case 2:
            traverse();
            break;
        case 3:
            reverse();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choise\n");
            break;
        }
    } while (choise != 4);
    return 0;
}
