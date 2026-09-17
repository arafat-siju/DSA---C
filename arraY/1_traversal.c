#include<stdio.h>
int main()
{
    int n, i;
    printf("Enter how many elements u want: ");
    scanf("%d", &n);

    int arr[n];         /*  n = int size = sizeof(arr) / sizeof(arr[0]);  */
    //taking input
    for(i = 0; i<n; i++){
        printf("Enter element for index arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    //print output
    printf("\nThe array is: \n");
    for(i = 0; i<n; i++){
        printf("element at index arr[%d] is: %d\n", i, arr[i]);
    }

    return 0;
}