#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMatrix(int *arr, int row, int col){
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            printf("%d ", *((arr + i * col) + j));
        }
    printf("\n");
    }
}

int main(){
    printf("Name: Manigandan R\nRegister number: 20BCE1223\n");
    int aRow = 0, aCol = 0, bRow = 0, bCol = 0;
    printf("Enter the number of rows for first matrix:");
    scanf("%d", &aRow);
    printf("Enter the number of columns for first matrix:");
    scanf("%d", &aCol);
    printf("Enter the number of rows for second matrix:");
    scanf("%d", &bRow);
    printf("Enter the number of columns for second matrix:");
    scanf("%d", &bCol);
    int A[aRow][aCol], B[bRow][bCol], MUL[aRow][bCol];
    
