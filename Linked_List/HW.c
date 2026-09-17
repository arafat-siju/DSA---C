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

void display(struct Node *head)
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d->", temp->item);
        temp = temp->next;
    }

    printf("NULL\n");
}

void insert_before(struct Node **head, int key, int value)
{
    struct Node *newNode;
    struct Node *temp;
    struct Node *prev;

    if (*head == NULL)
        return;

    if ((*head)->item == key)
    {
        newNode = create_new(value);
        newNode->next = *head;
        *head = newNode;
        return;
    }

    prev = *head;
    temp = (*head)->next;

    while (temp != NULL)
    {
        if (temp->item == key)
        {
            newNode = create_new(value);
            newNode->next = temp;
            prev->next = newNode;
            return;
        }

        prev = temp;
        temp = temp->next;
    }
}

void delete_node(struct Node **head, int key)
{
    struct Node *temp = *head;
    struct Node *prev = NULL;

    if (temp == NULL)
        return;

    if (temp->item == key)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->item != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

void process(struct Node **head)
{
    struct Node *temp = *head;

    while (temp != NULL)
    {
        if (temp->item == 20)
        {
            insert_before(head, 20, 15);
        }

        if (temp->item == 30)
        {
            delete_node(head, 20);
            return;
        }

        temp = temp->next;
    }
}

int main()
{
    struct Node *head = NULL;

    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    insert(&head, 50);
    insert(&head, 60);

    display(head);

    process(&head);

    display(head);

    return 0;
}