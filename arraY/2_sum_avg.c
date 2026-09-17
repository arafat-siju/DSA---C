#include<stdio.h>

int array_sum(int arr[], int size){
    int i, sum = 0;
    for(i = 0; i<size; i++){
        sum = sum + arr[i];
    }
    return sum;
}

float array_average(int arr[], int size){
    return (float)array_sum(arr,size) / size;
}

int main()
{
    int arr[] = {65, 60, 79, 83, 78, 59, 86, 68, 65, 80};

    int size = sizeof(arr) / sizeof(arr[0]);


    int x = array_sum(arr, size);
    float y = array_average(arr, size);
    
    printf("Sum of the elemetns is: %d\n", x);
    printf("Average of the element is: %.2f\n", y);

    return 0;
}