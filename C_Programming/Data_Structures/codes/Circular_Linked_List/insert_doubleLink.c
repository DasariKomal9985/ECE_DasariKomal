#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *head = NULL, *temp = NULL , *temp1 = NULL;
void insert()
{
    struct Node *newnode = malloc(sizeof(struct Node));
    if (newnode == NULL)
    {
        printf("Memory not allocated!\n");
        return;
    }
    printf("Enter data: "); 
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = temp = newnode;
    }
    else
    {
        temp->next = newnode;
        newnode->prev = temp;
        temp = newnode;
    }
}
void traverse()
{
    temp1 = head;
    while (temp1 != NULL)
    {
        printf("%d\t", temp1->data);
        temp1 = temp1->next;
    }
    printf("\n");
}
int main()
{
    int choice;
    do
    {
        printf("\n1.Insert\n2.traverse\n3.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            traverse();
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("\nInvalid Choice!");
            break;
        }
    } while (choice != 4);
}