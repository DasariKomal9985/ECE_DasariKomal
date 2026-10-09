#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int getlength();
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
struct Node *nextnode = NULL;
void deleteatposition()
{
    int position, i = 1, length = 0;
    printf("\nEnter the position to delete the node: ");
    scanf("%d", &position);
    length = getlength();
    current = tail->next;
    if (position < 1 || position > length)
    {
        printf("\nInvalid position! Please try again.");
        return;
    }
    if (position == 1)
    {
        printf("emptying node at position 1");
        return;
    }
    else
    {
        while (i < position - 1)
        {
            current = current->next;
            i++;
        }
        nextnode = current->next;
        current->next = nextnode->next;
        free(nextnode);
        printf("\nNode at position %d deleted successfully.", position);
        return;
    }
}
int getlength()
{
    int count = 0;
    current = tail->next;
    while (current != tail)
    {
        count++;
        current = current->next;
    }
    return count;
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
        printf("\n1. Insert at end\n2. Display\n3. deleteatposition\n4. Exit\n");
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
            deleteatposition();
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
