#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;


};

int isFull (struct stack* s){
    if (s -> top == s->size-1){
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

int push (struct stack *s, int value){
    if(isFull(s)){
        printf("\nStack is overflow: cannot push %d in the stack\n", value);
        return -1;
    }
    s -> top++;
    s -> arr[s->top] = value;
    return 0;
}

int pop (struct stack *s){
    if(isEmpty(s)){
        printf("\nStack underflow: can't pop from the stack\n");
        return -1;
    }

    int value = s->arr[s->top];
    s->top--;

    return value;
}

int peek(struct stack *s, int i){
    int index = s->top - i + 1;

    if (index < 0){
        printf("not a valid position.\n");
    }

    return s -> arr[index];
}



int main()
{
    struct stack* s = malloc(sizeof(struct stack));
    s -> size = 5;
    s -> top = -1;
    s -> arr = malloc(s -> size *sizeof(int));

    printf("stack created!!!!!!!\n");

    printf("%d\n", isEmpty(s));
    printf("%d\n", isFull(s));

    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    push(s, 50);
    push(s, 60);


    printf("%d\n", isEmpty(s));
    printf("%d\n", isFull(s));

    printf("\npopped %d from the stack\n", pop(s));
    printf("popped %d from the stack\n", pop(s));
    printf("popped %d from the stack\n", pop(s));
    printf("popped %d from the stack\n", pop(s));
    printf("popped %d from the stack\n", pop(s));
    printf("popped %d from the stack\n", pop(s));
    printf("popped %d from the stack\n", pop(s));

    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    push(s, 50);
    push(s, 60);

    int i = 1 ;
    for(i = 1; i <= s->top+1; i++){
        printf("\nthe value at position %d is %d", i, peek(s, i));
    }

    return 0;
}
