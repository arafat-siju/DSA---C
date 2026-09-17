#include<stdio.h>
int main()
{
    int arr[] = {67, 37, 46, 51, 41, 69, 77, 67, 59, 80};

    int size = sizeof(arr) / sizeof(arr[0]);
    int search, found = 0;
    printf("Enter the number what u want to search: ");
    scanf("%d", &search);

    for(int i = 0; i<size; i++){
        if(arr[i] == search){
            printf("%d is available in index arr[%d]", search, i);
            found = 1;
        }
    }

    if(found == 0){
    printf("%d is not available in the array", search);
    }

    return 0;
}