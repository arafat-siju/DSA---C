#include<stdio.h>
int main()
{
    int arr[] = {72, 43, 54, 72, 70, 72, 46, 56, 72, 44, 62, 35, 72};
    int size = sizeof(arr) / sizeof(arr[0]);
    int i, search, count = 0;

    printf("Enter which number you want to count: ");
    scanf("%d", &search);

    for(i = 0; i<size; i++){
        if(search == arr[i]){
            count++;
        }
    }
    if(count != 0){
        printf("%d found %d times", search, count);
    }
    else{
        printf("%d is not in the array!", search);
    }
    return 0;
}