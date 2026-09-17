#include <stdio.h>
#include <stdlib.h>

struct Node{
    int item;
    struct Node *next;
};
struct Node *top = NULL;

int isEmpty(struct Node *top){
    if (top == NULL){
        return 1;
    }
    return 0;
}

int isFull(){
    struct Node *p = malloc(sizeof(struct Node));
    if (p == NULL){
        return 1;
    }
    free(p);
    return 0;
}


struct Node *push(struct Node *top, int value){
    if (isFull()){
        printf("stack overflow\n");
        return top;
    }

    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->item = value;
    newNode->next = top;

    return newNode;
}

int pop(struct Node **top){
    if (isEmpty(*top)){
        printf("stack underflow\n");
        return -1;
    }

    struct Node *temp = *top;
    int value = temp->item;
    *top = temp->next;
    free(temp);

    return value;
}

void display(struct Node *top){
    if(top == NULL){
        printf("Stack is empty!\n");
        return;
    }
    while (top != NULL){
        printf("%d -> ", top->item);
        top = top->next;
    }
    printf("NULL\n");
}

// MAX & MIN
void max_min(struct Node *top){
    if(top == NULL) {
        printf("Stack is empty");
        return;
    }
    int max = top->item;
    int min = top->item;

    top = top->next;

    while(top != NULL){
        if(top->item > max){
            max = top->item;
        }
        if(top->item < min){
            min = top->item;
        }
        top = top->next;
    }
    printf("Largest Number: %d\n", max);
    printf("Smallest Number: %d\n", min);
}

// find positon of item
int position(struct Node *top, int value){
    int position = 1;

    while (top != NULL){
        if(top->item == value){
            return position;
        }

        top = top->next;
        position++;
    }
    return 404;
}

// reverse the stack
void reverse(struct Node **top){
    struct Node *previous = NULL;
    struct Node *current = *top;
    struct Node *next;

    while(current != NULL){
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    *top = previous;
    printf("stack reversed successfully\n");
}


int main()
{
    int i, n, value, choice, pos;

    printf("Enter how many data u want: ");
    scanf("%d", &n);

    for (i = 0; i<n; i++){
        printf("enter data %d: ", i+1);
        scanf("%d", &value);

        top = push(top, value);
    }

    printf("\nStack is: ");
    display(top);

    printf("\n1. Max & Min element"
            "\n2. clear the stack"
            "\n3. find element's position"
            "\n4. reverse the stack."
            "\nEnter your choice(1-4): ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            max_min(top);
            break;

        case 2:
            while(top != NULL){
                pop(&top);
            }
            display(top);
            break;

        case 3:
            printf("\nEnter the value u want to find: ");
            scanf("%d", &value);

            pos = position(top, value);

            if(pos == 404)
                printf("%d is not found.\n");
            else
                printf("%d is at positon %d", value, pos);
            break;

        case 4:
            printf("\n stack before: ");
            display(top);

            reverse(&top);

            printf("\nstack after reversed: ");
            display(top);
            break;

        default: printf("\nINVALID choice.\n");
    }
    return 0; 
}