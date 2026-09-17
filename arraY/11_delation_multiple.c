#include <stdio.h>

int main() {
    int arr[] = {10, 10, 20, 30, 10, 40, 50, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    int deleteVals[] = {10, 30};
    int delSize = sizeof(deleteVals) / sizeof(deleteVals[0]);

    int i, j, k;

    for (i = 0; i < size; i++) {
        int shouldDelete = 0;
        for (k = 0; k < delSize; k++) {
            if (arr[i] == deleteVals[k]) {
                shouldDelete = 1;
                break;
            }
        }

        if (shouldDelete) {
            for (j = i; j < size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            size--;
            i--;
        }
    }

    // print result
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i], size);
    }

    return 0;
}
