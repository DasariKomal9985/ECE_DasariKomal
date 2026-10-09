#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL, *temp = NULL, *newNode = NULL , *previous = NULL;
void deleteAtEnd()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        temp = head;
        previous = temp;
        while (temp->next != NULL)
        {
            previous = temp;
            temp = temp->next;
        }
        free(temp);
       previous->next = NULL;
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
    int choise;
    do
    {
        printf("1. Insert at begin\n2. delete at end\n3. Traverse\n4. Exit\n");
        printf("Enter your choise: ");
        scanf("%d", &choise);
        switch (choise)
        {
        case 1:
            insertAtBegin();
            break;
        case 2:
            deleteAtEnd();
            break;
        case 3:
            traverse();
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
