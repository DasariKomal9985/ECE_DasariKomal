#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL, *temp = NULL, *newNode = NULL;
void deleteAtSpecific()
{
    int position, i = 1;
    struct Node *prev = NULL;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Enter the position to delete: ");
    scanf("%d", &position);
    temp = head;
    while (i < position - 1)
    {
        temp = temp->next;
        i++;
    }
    if (temp == NULL)
    {
        printf("Position out of bounds\n");
        return;
    }
    prev = temp->next;
    temp->next = prev->next;
    free(prev);
    printf("Node deleted at position %d\n", position);
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
        printf("1. Insert at begin\n2. deleteAtSpecific\n3. traverse\n4. Exit\n");
        printf("Enter your choise: ");
        scanf("%d", &choise);
        switch (choise)
        {
        case 1:
            insertAtBegin();
            break;
        case 2:
            deleteAtSpecific();
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
