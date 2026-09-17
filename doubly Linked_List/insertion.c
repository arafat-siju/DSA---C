//insertion
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int item;
    struct Node* next;
    struct Node* prev;
};

struct Node* create_new(int value) {
    struct Node* p = (struct Node*) malloc(sizeof(struct Node));
    p->item = value;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

void insert(struct Node** head, int value) {
    struct Node* newNode = create_new(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insert_after_key(struct Node** head, int key, int value) {
    struct Node* temp = *head;
    while (temp != NULL && temp->item != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Data Not Found\n");
        return;
    }
    struct Node* newNode = create_new(value);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void display(struct Node* temp) {
    while (temp != NULL) {
        printf("%d<->", temp->item);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    insert(&head, 50);
    display(head);

    insert_after_key(&head, 20, 25);
    display(head);

    insert_after_key(&head, 50, 60);
    display(head);

    insert_after_key(&head, 100, 99);

    return 0;
}