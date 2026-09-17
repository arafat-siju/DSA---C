#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40};
    int size = sizeof(arr) / sizeof(arr[0]);
    int value;

    printf("Enter the value you want to add at the end: ");
    scanf("%d", &value);

    arr[size] = value;
    size++;

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
