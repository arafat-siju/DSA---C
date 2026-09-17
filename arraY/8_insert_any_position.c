#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int i, value,  index;

    printf("enter the value you to insert: ");
    scanf("%d", &value);
    printf("Enter the index where you want to add: ");
    scanf("%d", &index);

    for (i = size; i > index; i--) {
        arr[i] = arr[i-1];
    }
    arr[index] = value;
    size++;

    for (i = 0; i < size; i++) {
        printf("%d, ", arr[i]);
    }
    return 0;
}
