#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL, *temp = NULL, *newNode = NULL;
void findLength()
{
    int length = 0;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            length++;
            temp = temp->next;
        }
        printf("The length of the linked list is: %d\n", length);
    }
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
    int choice;
    do
    {
        printf("1. Insert at begin\n2. Find Length\n3. Traverse\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertAtBegin();
            break;
        case 2:
            findLength();
            break;
        case 3:
            traverse();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 4);
    return 0;
}
