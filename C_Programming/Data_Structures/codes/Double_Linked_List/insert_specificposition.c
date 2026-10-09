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

/* ================= Insert at Specific Position ================= */
void insert_at_position()
{
    int pos, i = 1;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos <= 0)
    {
        printf("Invalid position\n");
        return;
    }

    newnode = (struct Node*)malloc(sizeof(struct Node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    /* Case 1: Insert at beginning */
    if (pos == 1)
    {
        newnode->prev = NULL;
        newnode->next = head;

        if (head != NULL)
            head->prev = newnode;
        else
            tail = newnode;

        head = newnode;
        return;
    }

    temp = head;

    while (temp != NULL && i < pos - 1)
    {
        temp = temp->next;
        i++;
    }

    if (temp == NULL)
    {
        printf("Position out of range\n");
        free(newnode);
        return;
    }

    /* Insert at end */
    if (temp->next == NULL)
    {
        newnode->next = NULL;
        newnode->prev = temp;
        temp->next = newnode;
        tail = newnode;
    }
    else
    {
        /* Insert in middle */
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next->prev = newnode;
        temp->next = newnode;
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
        printf("3. Insert at position\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
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
                insert_at_position();
                break;

            case 4:
                Traverse();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 5);

    return 0;
}