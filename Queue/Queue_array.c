#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

// Queue Size
int queueSize(struct Queue *q)
{
    return q->rear - q->front;
}

// Largest and Smallest Element
void largestSmallest(struct Queue *q)
{
    int largest = q->arr[q->front + 1];
    int smallest = q->arr[q->front + 1];

    for(int i=q->front+1; i<=q->rear; i++)
    {
        if(q->arr[i] > largest)
            largest = q->arr[i];

        if(q->arr[i] < smallest)
            smallest = q->arr[i];
    }

    printf("Largest Element = %d\n", largest);
    printf("Smallest Element = %d\n", smallest);
}

// Clear Queue
void clearQueue(struct Queue *q)
{
    q->front = -1;
    q->rear = -1;

    printf("Queue Cleared Successfully.\n");
}

// Find Position
void findPosition(struct Queue *q, int value)
{
    for(int i=q->front+1; i<=q->rear; i++)
    {
        if(q->arr[i] == value)
        {
            printf("Position = %d\n", i-(q->front));
            return;
        }
    }
    printf("Element Not Found.\n");
}

// Reverse Queue
void reverseQueue(struct Queue *q)
{
    int start = q->front + 1;
    int end = q->rear;

    while(start < end)
    {
        int temp = q->arr[start];
        q->arr[start] = q->arr[end];
        q->arr[end] = temp;

        start++;
        end--;
    }

    printf("Queue Reversed.\n");

    printf("New Queue : ");
    for(int i=q->front+1; i<=q->rear; i++)
        printf("%d ", q->arr[i]);
    printf("\n");
}

int main()
{
    int n, choice, value;

    printf("How many elements do you want to insert:  ");
    scanf("%d",&n);

    struct Queue *q = malloc(sizeof(struct Queue));

    q->size = n;
    q->front = -1;
    q->rear = -1;
    q->arr = malloc(n*sizeof(int));

    for(int i = 0; i<n; i++)
    {
        printf("Enter Queue Element: ");
        scanf("%d",&value);
        q->rear++;
        q->arr[q->rear] = value;
    }


    printf("\n1. Queue Size\n"
        "2. Largest and Smallest Element\n"
        "3. Clear Queue\n"
        "4. Find Position\n"
        "5. Reverse Queue\n");

    printf("Enter Choice: ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            printf("Queue Size = %d\n", queueSize(q));
            break;

        case 2:
            largestSmallest(q);
            break;

        case 3:
            clearQueue(q);
            break;

        case 4:
            printf("Enter Element to Search: ");
            scanf("%d",&value);
            findPosition(q,value);
            break;

        case 5:
            reverseQueue(q);
            break;

        default:
            printf("Invalid Choice.\n");
    }

    return 0;
}