#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int size, front, rear;
    int *arr;
};

int queueSize(struct Queue *q){
    return (q->rear) - (q->front);
}

int enqueue(struct Queue *q, int value){
    q->rear++;
    q->arr[q->rear] = value;
    return 0;
}

int dequeue(struct Queue *q){
    q->front++;
    return q->arr[q->front];
}

void position(struct Queue *q, int value){

    for(int i = q->front+1; i <= q->rear; i++){
        if(q->arr[i] == value){
            printf("position = %d\n", i-(q->front));
            return;
        }
    }
    printf("Element is not present\n");
}

void reverse(struct Queue *q){
    int start = q->front + 1;
    int end = q->rear;

    while (start < end){
        int temp = q->arr[start];
        q->arr[start] = q->arr[end];
        q->arr[end] = temp;

        start++;
        end--;
    }
}

void max_min(struct Queue *q){
    int max = q->arr[q->front +1];
    int min = q->arr[q->front +1];

    for (int i = q->front+1; i<= q->rear; i++){
        if (q->arr[i] > max){
            max = q->arr[i];
        }
        if (q->arr[i] < min){
            min = q->arr[i];
        }
    }
    
    printf("\nLargest is: %d\n", max);
    printf("Smallest is: %d\n", min);
}

void display(struct Queue *q){
    for(int i=q->front+1; i<=q->rear; i++)
        printf("%d\t", q->arr[i]);
    printf("\n");

    if(q->rear == q->front){
        printf("Queue is EMPTY !!\n");
    }
}

int main()
{
    int n, choice, value;
    printf("How many elements u want: ");
    scanf("%d", &n);

    struct Queue *q = malloc(sizeof(struct Queue));

    q->size = n;
    q->front = -1;
    q->rear = -1;
    q->arr = malloc(n*sizeof(int));

    for(int i = 0; i < n; i++){
        printf("Enter element: ");
        scanf("%d", &value);
        enqueue(q, value);
    }

    printf("\nQueue is: ");
    display(q);

    printf("\n1. Queue Size.\n"
        "2. Largest and Smallest element.\n"
        "3. Clear Queue\n"
        "4. Find Position.\n"
        "5. Reverse Queue\n");

    printf("\nEnter choice: ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            printf("Queue Size = %d\n", queueSize(q));
            break;

        case 2:
            max_min(q);
            break;

        case 3:
            for (int i = 0; i < n; i++){
                dequeue(q);
            }
            display(q);
            break;

        case 4:
            printf("\nEnter element to search: ");
            scanf("%d", &value);
            position(q, value);
            break;
        
        case 5:
            reverse(q);
            display(q);
            break;

        default:
            printf("\nInvalid CHOICE !!\n");
    }
    return 0;
}