#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL, *temp = NULL, *newNode = NULL;
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
        printf("1. Insert at begin\n2. Traverse\n3. Exit\n");
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
            exit(0);
            break;
        default:
            printf("Invalid choise\n");
            break;
        }
    } while (choise != 4);
    return 0;
}
