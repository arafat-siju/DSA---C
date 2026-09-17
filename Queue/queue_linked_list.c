#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int item;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

// Enqueue
void enqueue(int value)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->item = value;
    newNode->next = NULL;

    if(front == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

// Queue Size
int queueSize()
{
    int count = 0;
    struct Node *temp = front;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

// Largest and Smallest
void largestSmallest()
{
    struct Node *temp = front;

    int largest = temp->item;
    int smallest = temp->item;

    while(temp != NULL)
    {
        if(temp->item > largest)
            largest = temp->item;

        if(temp->item < smallest)
            smallest = temp->item;

        temp = temp->next;
    }

    printf("Largest Element = %d\n", largest);
    printf("Smallest Element = %d\n", smallest);
}

// Clear Queue
void clearQueue()
{
    struct Node *temp;

    while(front != NULL)
    {
        temp = front;
        front = front->next;
        free(temp);
    }

    rear = NULL;

    printf("Queue Cleared Successfully.\n");
}

// Find Position
void findPosition(int value)
{
    struct Node *temp = front;
    int pos = 1;

    while(temp != NULL)
    {
        if(temp->item == value)
        {
            printf("Position = %d\n", pos);
            return;
        }

        pos++;
        temp = temp->next;
    }

    printf("Element Not Found.\n");
}

// Reverse Queue
void reverseQueue()
{
    struct Node *prev = NULL;
    struct Node *current = front;
    struct Node *next;

    rear = front;

    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    front = prev;

    printf("Queue Reversed.\n");

    struct Node *temp = front;

    printf("New Queue : ");

    while(temp != NULL)
    {
        printf("%d ", temp->item);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    int n, value, choice;

    printf("How many nodes do you want to insert? ");
    scanf("%d",&n);

    printf("Enter Queue Elements:\n");

    for(int i=0;i<n;i++)
    {
        scanf("%d",&value);
        enqueue(value);
    }

    printf("\n1. Queue Size\n");
    printf("2. Largest and Smallest Element\n");
    printf("3. Clear Queue\n");
    printf("4. Find Position\n");
    printf("5. Reverse Queue\n");

    printf("Enter Choice: ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            printf("Queue Size = %d\n", queueSize());
            break;

        case 2:
            largestSmallest();
            break;

        case 3:
            clearQueue();
            break;

        case 4:
            printf("Enter Element to Search: ");
            scanf("%d",&value);
            findPosition(value);
            break;

        case 5:
            reverseQueue();
            break;

        default:
            printf("Invalid Choice.\n");
    }

    return 0;
}