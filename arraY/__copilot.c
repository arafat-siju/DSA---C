#include <stdio.h>
#include <stdlib.h>

#define ROWS 4
#define COLS 3

void shiftColumnRight(int **arr, int rows, int cols, int col) {
    // Allocate new matrix with one extra column
    int **newArr = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        newArr[i] = (int *)malloc((cols + 1) * sizeof(int));
    }

    // Copy values with shift
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < col; j++) {
            newArr[i][j] = arr[i][j]; // left side unchanged
        }
        newArr[i][col] = 0; // chosen column becomes empty
        for (int j = col; j < cols; j++) {
            newArr[i][j + 1] = arr[i][j]; // shift right
        }
    }

    // Print new matrix
    printf("\nMatrix after shifting column %d:\n", col);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols + 1; j++) {
            printf("%d\t", newArr[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < rows; i++) {
        free(newArr[i]);
    }
    free(newArr);
}

int main() {
    int matrix[ROWS][COLS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}
    };

    printf("Original Matrix:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    int col;
    printf("\nEnter column index (0-%d) to shift: ", COLS - 1);
    scanf("%d", &col);

    if (col >= 0 && col < COLS) {
        // Convert static matrix to dynamic pointer array
        int **ptrMatrix = (int **)malloc(ROWS * sizeof(int *));
        for (int i = 0; i < ROWS; i++) {
            ptrMatrix[i] = (int *)malloc(COLS * sizeof(int));
            for (int j = 0; j < COLS; j++) {
                ptrMatrix[i][j] = matrix[i][j];
            }
        }

        shiftColumnRight(ptrMatrix, ROWS, COLS, col);

        for (int i = 0; i < ROWS; i++) free(ptrMatrix[i]);
        free(ptrMatrix);
    } else {
        printf("Invalid column index!\n");
    }

    return 0;
}
