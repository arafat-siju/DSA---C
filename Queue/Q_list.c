#include <stdio.h>
#include <stdlib.h>

struct Node{
    int item;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int value){
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->item = value;
    newNode->next = NULL;

    if(front == NULL){
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue(){
    if(front == NULL)
        return;
    struct Node *temp = front;
    front = front->next;
    free(temp);
}

int queueSize(){
    int count = 0;
    struct Node *temp = front;

    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

void max_min(){
    struct Node *temp = front;
    int max = temp->item;
    int min = temp->item;

    while(temp != NULL){
        if (temp->item > max){
            max = temp->item;
        }
        if (temp->item <min){
            min = temp->item;
        }
        temp = temp->next;
    }
    printf("\nLargest is: %d\n", max);
    printf("Smallest is: %d\n", min);
}

void position(int value){
    struct Node *temp = front;
    int pos = 1;

    while(temp != NULL) {
        if(temp->item == value) {
            printf("Position = %d\n", pos);
            return;
        }
        pos++;
        temp = temp->next;
    }
    printf("Element Not Found.\n");
}

void reverse(){
    struct Node *prev = NULL;
    struct Node *current = front;
    struct Node *next;

    rear = front;

    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    front = prev;
}

void display() {
    struct Node *temp = front;

    while(temp != NULL) {
        printf("%d -> ", temp->item);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main()
{
    int i, n, value, choice;
    printf("Enter how many number u want: ");
    scanf("%d", &n);

    for(i = 0; i<n; i++){
        printf("Enter value: ");
        scanf("%d", &value);
        enqueue(value);
    }
    
    printf("\nQueue is: ");
    display();

    printf("\n1. Queue Size.\n"
        "2. Largest and Smallest element.\n"
        "3. Clear Queue\n"
        "4. Find Position.\n"
        "5. Reverse Queue\n");

    printf("\nEnter choice: ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            printf("Queue Size = %d\n", queueSize());
            break;

        case 2:
            max_min();
            break;

        case 3:
            for (int i = 0; i < n; i++){
                dequeue();
            }
            display();
            break;

        case 4:
            printf("\nEnter element to search: ");
            scanf("%d", &value);
            position(value);
            break;
        
        case 5:
            reverse();
            display();
            break;

        default:
            printf("\nInvalid CHOICE !!\n");
    }
    return 0;
}