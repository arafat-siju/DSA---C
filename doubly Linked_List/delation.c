//delation
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

void delete_node(struct Node** head, int key) {
    struct Node* temp = *head;
    if (temp != NULL && temp->item == key) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }
    while (temp != NULL && temp->item != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Data Not Found\n");
        return;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
}

void delete_after_key(struct Node** head, int key) {
    struct Node* temp = *head;
    while (temp != NULL && temp->item != key) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Data Not Found\n");
        return;
    }
    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    if (toDelete->next != NULL) {
        toDelete->next->prev = temp;
    }
    free(toDelete);
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

    delete_node(&head, 30);
    display(head);

    delete_node(&head, 10);
    display(head);

    delete_after_key(&head, 20);
    display(head);

    delete_node(&head, 100);

    return 0;
}