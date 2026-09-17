#include<stdio.h>
int main()
{
    int arr[] = {43, 5004, 72, 70, 72, 46, 56, 44, 62, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int x, y, max = arr[0], min = arr[0];

    for(int i = 0; i<size; i++){
        if(arr[i] > max){
            max = arr[i];
            x = i;
        }
        else if(arr[i] < min){
            min = arr[i];
            y = i;
        }
    }
    printf("Maximum numebr is: %d and index is: arr[%d]\n", max, x);
    printf("Minimum numebr is: %d and index is: arr[%d]\n", min, y);
    
    return 0;
}