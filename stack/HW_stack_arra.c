#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isFull(struct stack *s){
    if(s->top == s->size - 1){
        return 1;
    }
    return 0;
}

int isEmpty(struct stack *s){
    if(s->top < 0){
        return 1;
    }
    return 0;
}

int push(struct stack *s, int value){
    if(isFull(s)){
        printf("Stack overflow\n");
        return -1;
    }

    s->top++;
    s->arr[s->top] = value;

    return 0;
}

int pop(struct stack *s){
    if(isEmpty(s)){
        printf("Stack underflow\n");
        return -1;
    }

    int value = s->arr[s->top];
    s->top--;

    return value;
}

void display(struct stack *s){
    if(isEmpty(s)){
        printf("Stack is empty!\n");
        return;
    }

    for(int i = s->top; i >= 0; i--){
        printf("%d -> ", s->arr[i]);
    }

    printf("NULL\n");
}

void max_min(struct stack *s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
        return;
    }

    int max = s->arr[s->top];
    int min = s->arr[s->top];

    for(int i = s->top - 1; i >= 0; i--){
        if(s->arr[i] > max){
            max = s->arr[i];
        }

        if(s->arr[i] < min){
            min = s->arr[i];
        }
    }

    printf("Largest Number: %d\n", max);
    printf("Smallest Number: %d\n", min);
}

int position(struct stack *s, int value){
    int position = 1;

    for(int i = s->top; i >= 0; i--){
        if(s->arr[i] == value){
            return position;
        }

        position++;
    }

    return 404;
}

void reverse(struct stack *s){
    int i = 0;
    int j = s->top;
    int temp;

    while(i < j){
        temp = s->arr[i];
        s->arr[i] = s->arr[j];
        s->arr[j] = temp;

        i++;
        j--;
    }

    printf("stack reversed successfully\n");
}

int main()
{
    int i, n, value, choice, pos;

    printf("Enter how many data u want: ");
    scanf("%d", &n);

    struct stack *s = malloc(sizeof(struct stack));

    s->size = n;
    s->top = -1;
    s->arr = malloc(s->size * sizeof(int));

    for(i = 0; i < n; i++){
        printf("enter data %d: ", i + 1);
        scanf("%d", &value);

        push(s, value);
    }

    printf("\nStack is: ");
    display(s);

    printf("\n1. Max & Min element"
           "\n2. clear the stack"
           "\n3. find element's position"
           "\n4. reverse the stack."
           "\nEnter your choice(1-4): ");
    scanf("%d", &choice);

    switch(choice){

        case 1:
            max_min(s);
            break;

        case 2:
            while(!isEmpty(s)){
                pop(s);
            }

            display(s);
            break;

        case 3:
            printf("\nEnter the value u want to find: ");
            scanf("%d", &value);

            pos = position(s, value);

            if(pos == 404)
                printf("%d is not found.\n", value);
            else
                printf("%d is at positon %d", value, pos);

            break;

        case 4:
            printf("\nstack before: ");
            display(s);

            reverse(s);

            printf("\nstack after reversed: ");
            display(s);

            break;

        default:
            printf("\nINVALID choice.\n");
    }

    free(s->arr);
    free(s);

    return 0;
}