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
void deleteatbegin()
{
    if (tail == NULL)
    {
        printf("\nThe list is empty! Deletion not possible.");
        return;
    }
    temp = tail->next; // head
    if (tail->next == tail) // only one node
    {
        head = NULL;
        tail = NULL;
    }
    else
    {
        tail->next = temp->next;
    }
    printf("\nDeleted element: %d\n", temp->data);
    free(temp);
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
        printf("\n1. Insert at end\n2. Display\n3. deleteatbegin\n4. Exit\n");
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
            deleteatbegin();
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
