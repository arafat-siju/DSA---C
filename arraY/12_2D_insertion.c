#include<stdio.h>
int main()
{
    int row, col;
    printf("Enter row: ");
    scanf("%d", &row);
    printf("Enter column: ");
    scanf("%d", &col);

    int arr[row][col];
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
    
    char choice;
    printf("\ntype where you want to insert the values.\n");
    printf("along row type 'r', along column type 'c': ");
    scanf("%c", choice);

    int position;
    printf("Enter the placement: ");
    scanf("%d", &position);

    if(choice == 'c'){
        for (i = row; i > position; i--) {
            for (j = col; j > position, j--) {
                
            }
        }
    }

    return 0;
}