#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int item;
    struct Node *next;
};

struct Node *create_new(int value)
{
    struct Node *p;
    p = (struct Node *)malloc(sizeof(struct Node));
    p->item = value;
    p->next = NULL;
    return p;
}

void insert(struct Node **head, int value)
{
    struct Node *newNode = create_new(value);
    struct Node *temp = *head;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void insert_after_key(struct Node **head, int key, int value)
{
    struct Node *temp = *head;
    struct Node *newNode = create_new(value);

    while (temp != NULL && temp->item != key)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Data Not Found\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void display(struct Node *temp)
{
    while (temp != NULL)
    {
        printf("%d->", temp->item);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;

    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    insert(&head, 50);

    display(head);

    insert_after_key(&head, 20, 25);

    display(head);

    return 0;
}