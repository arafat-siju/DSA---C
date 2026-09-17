#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40};
    int size = sizeof(arr) / sizeof(arr[0]); 
    int i, value;

    printf("Enter what number you want to insert at first: ");
    scanf("%d", &value);

    for (i = size; i > 0; i--) {
        arr[i] = arr[i-1];
    }
    arr[0] = value;
    size++;


    for (int i = 0; i < size; i++) {
        printf("%d, ", arr[i]);
    }
    return 0;
}
