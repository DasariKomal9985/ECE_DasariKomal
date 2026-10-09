#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* head = NULL;
struct Node* tail = NULL;
struct Node* temp = NULL;
struct Node* newnode = NULL;

/* ================= Traverse ================= */
void Traverse()
{
    temp = head;

    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("The elements in the list are:\n");

        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

/* ================= Insert at Beginning ================= */
void insert_at_beg()
{
    newnode = (struct Node*)malloc(sizeof(struct Node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->prev = NULL;
    newnode->next = head;

    if (head == NULL)
    {
        head = tail = newnode;
    }
    else
    {
        head->prev = newnode;
        head = newnode;
    }
}

/* ================= Insert at End ================= */
void insert_at_end()
{
    newnode = (struct Node*)malloc(sizeof(struct Node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;
    newnode->prev = tail;

    if (head == NULL)
    {
        head = tail = newnode;
    }
    else
    {
        tail->next = newnode;
        tail = newnode;
    }
}

/* ================= Main ================= */
int main()
{
    int choice;

    do
    {
        printf("\n1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert_at_beg();
                break;

            case 2:
                insert_at_end();
                break;

            case 3:
                Traverse();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 4);

    return 0;
}