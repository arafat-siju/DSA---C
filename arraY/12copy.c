#include<stdio.h>
#define row 4
#define col 4
int main()
{
    // int row = 4, col = 4;
    int arr[row][col] = {
        {1, 2, 3, 4},
        {7, 4, 5, 6},
        {7, 3, 0, 11},
        {5, 8, 9, 7}
    };

    //input
    int i, j;
    for (i = 0; i < row; i++){
        for (j = 0; j < col; j++){
            printf("Enter value [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    //output
    pritnf("\nThe matrix is: \n");
    for (i = 0; i < row; i++){
        for (j = 0; j < col; j++){
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}