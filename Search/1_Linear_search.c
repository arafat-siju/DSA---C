#include <stdio.h>
#include <stdlib.h>

int linear_search(int arr[], int size, int element){
    for (int i = 0; i<size; i++){
        if (arr[i] == element)
            return i;
    }

    return 404;
}

int main()
{
    int i, x, size, element;

    printf("Enter the size of array: ");
    scanf("%d", &size);
    
    int arr[size];

    for (i = 0; i<size; i++){
        printf("Enter element for index %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nThe array is: ");
    for(i = 0; i<size; i++){
        printf("%d\t", arr[i]);
    }

    printf("\n\nEnter which element you want to find: ");
    scanf("%d", &element);

    x = linear_search(arr, size, element);

    if (x == 404)
        printf("NOT FOUND !");
    else
        printf("\nThe index of the element is: %d", x);

    return 0;
}