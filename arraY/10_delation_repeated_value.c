#include <stdio.h>

int main() {
    int arr[] = {10, 10, 20, 30, 10, 40, 50, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    int value, i, j, found = 0;

    printf("Enter the value you want to delete: ");
    scanf("%d", &value);

    for (i = 0; i < size; i++) {
        if (arr[i] == value) {
            found = 1;
            for (j = i; j < size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            size--;
            i--;
        }
    }

    if (found == 0) {
        printf("Value not found!\n");
    }

    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
