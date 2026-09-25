#include <stdio.h>
#include <stdlib.h>

int bin_search(int arr[], int size, int element){
    int low = 0;
    int high = size - 1;
    int mid;

    if (arr[low] == element)
        return low;

    if (arr[high] == element)
        return high;
    
    for ( ; low <= high ; ){         //while(low <= high)
        mid = (low + high) / 2;

        if (arr[mid] == element)
            return mid;

        if(arr[mid] > element)
            high = mid - 1;

        if(arr[mid] < element)
            low = mid + 1;
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
        printf("enter value for index %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nThe array is: ");
    
    for (i = 0; i<size; i++){
        printf("%d\t", arr[i]);
    }

    printf("\n\nwhich element u want to search: ");
    scanf("%d", &element);

    x = bin_search(arr, size, element);

    if (x == 404)
        printf("NOT FOUND !");
    else
        printf("\nIndex of the element %d is: %d\n", element, x);

    return 0;
}