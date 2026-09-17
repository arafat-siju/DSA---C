#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct Queue *q) {
    if((q->rear+1) % q->size == q->front){
        return 1;
    }
    else
        return 0;
}

int isEmpty(struct Queue *q) {
    if(q->rear  == q->front){
        return 1;
    }
    else
        return 0;
}

int enqueue(struct Queue *q, int value) {
    if(isFull(q)){
        printf("the queue is FULL !!.\n");
        return -1;
    }

    q->rear++;
    q->arr[q->rear] = value;
    return 0;
}

int dequeue(struct Queue *q){
    if(isEmpty(q)) {
        printf("the QUEUE is empty.\n");
        return -1;
    }

    q->front++;
    return q->arr[q->front];
}


int main()
{
    struct Queue *q = malloc(sizeof(struct Queue));
    q->size = 5;
    q->front = 0;
    q->rear = 0;
    q->arr = malloc(q->size *sizeof(int));
    
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    
    // printf("%d \n", isFull(q));
    // printf("%d \n", isEmpty(q));
    
    printf("\nthe dequeueing element %d\n", dequeue(q));
    printf("the dequeueing element %d\n", dequeue(q));
    printf("the dequeueing element %d\n", dequeue(q));
    
    enqueue(q, 60);
    enqueue(q, 70);
    enqueue(q, 70);
    
    printf("\nthe dequeueing element %d\n", dequeue(q));
    printf("the dequeueing element %d\n", dequeue(q));
    printf("the dequeueing element %d\n", dequeue(q));
    
    return 0;
}