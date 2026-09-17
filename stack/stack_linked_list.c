#include <stdio.h>
#include <stdlib.h>

struct Node{
    int item;
    struct Node *next;
};

struct Node *top = NULL;


int isFull(){
    struct Node *p = malloc(sizeof(struct Node));
    if (p == NULL){
        return 1;
    }
    return 0;
}

int isEmpty(struct Node *top){
    if(top == NULL){
        return 1;
    }
    return 0;
}

struct Node *push(struct Node *top, int value){
    if (isFull(top)){
        printf("stack overflow!!!\n");
        return top;
    }
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->item = value;
    newNode->next = top;

}

int pop(struct Node **top){
    if(isEmpty(*top)){
        printf("Stack underflow!!!\n");
        return -1;
    }
    struct Node *temp = *top;
    int value = temp->item;
    *top = temp->next;
    free(temp);
    return value;
}

void traversal (struct Node *temp){
    while(temp != NULL){
        printf("%d -> ", temp->item);
        temp = temp->next;
    }
    printf("NULL");
}



int main(){

    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);

    traversal(top);

    printf("\npopped -> %d from stack.\n", pop(&top));
    traversal(top);

    return 0;
}
