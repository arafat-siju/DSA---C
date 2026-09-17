//traversal
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

void display_forward(struct Node* temp) {
    while (temp != NULL) {
        printf("%d<->", temp->item);
        temp = temp->next;
    }
    printf("NULL\n");
}

void display_backward(struct Node* head) {
    if (head == NULL) {
        printf("NULL\n");
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    while (temp != NULL) {
        printf("%d<->", temp->item);
        temp = temp->prev;
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

    printf("Forward:  ");
    display_forward(head);

    printf("Backward: ");
    display_backward(head);

    return 0;
}