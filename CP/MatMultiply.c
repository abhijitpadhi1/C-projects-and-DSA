/* Written with inserting the function -> Giving wrong output */
// #include<stdio.h>
// void multiplyMat(int mat1[][10],int mat2[][10],int row1,int col1,int row2,int col2);
// void main(){
//     int row1,col1,row2,col2;
//     printf("Enter the row and col for first matrix\n");
//     scanf("%d%d",&row1,&col1);
//     printf("Enter the row and col for second matrix\n");
//     scanf("%d%d",&row2,&col2);
//     int mat1[row1][col1],mat2[row2][col2];
//     printf("Enter the first matrix elements\n");
//     for (int i = 0; i < row1; i++){
//         for (int j = 0; j < col1; j++)
//             scanf("%d",&mat1[i][j]);
//     }
//     printf("Enter the second matrix elements\n");
//     for (int i = 0; i < row2; i++){
//         for (int j = 0; j < col2; j++)
//             scanf("%d",&mat2[i][j]);
//     }
//     multiplyMat(mat1,mat2,row1,col1,row2,col2);
// }
// void multiplyMat(int mat1[][10],int mat2[][10],int row1,int col1,int row2,int col2){
//     if(col1 == row2){
//         int mul[row1][col2],i,j,k;
//         for (i = 0; i < row1; i++){
//             for (j = 0; j < col2; j++){
//                 mul[i][j] = 0;
//                 for(k=0; k<row2; k++){
//                     mul[i][j] += mat1[i][k] * mat2[k][j];
//                 }            
//             }
//         }
//         printf("The matrix after multiplication\n");
//         for (int i = 0; i < row1; i++){
//             for (int j = 0; j < col2; j++)
//                 printf("%d ",mul[i][j]);
//             printf("\n");
//         }
//     }
//     else
//         printf("This multiplication is not posible");
// }

/* Wrtitten with out inserting the function -> Giving correct output */
// #include<stdio.h>
// void main(){
//     int row1,col1,row2,col2;
//     printf("Enter the row and col for first matrix\n");
//     scanf("%d%d",&row1,&col1);
//     printf("Enter the row and col for second matrix\n");
//     scanf("%d%d",&row2,&col2);
//     int mat1[row1][col1],mat2[row2][col2];
//     printf("Enter the first matrix elements\n");
//     for (int i = 0; i < row1; i++){
//         for (int j = 0; j < col1; j++)
//             scanf("%d",&mat1[i][j]);
//     }
//     printf("Enter the second matrix elements\n");
//     for (int i = 0; i < row2; i++){
//         for (int j = 0; j < col2; j++)
//             scanf("%d",&mat2[i][j]);
//     }
//     int mul[row1][col2],i,j,k;
//         for (i = 0; i < row1; i++){
//             for (j = 0; j < col2; j++){
//                 mul[i][j] = 0;
//                 for(k=0; k<row2; k++){
//                     mul[i][j] += mat1[i][k] * mat2[k][j];
//                 }            
//             }
//         }
//         printf("The matrix after multiplication\n");
//         for (int i = 0; i < row1; i++){
//             for (int j = 0; j < col2; j++)
//                 printf("%d ",mul[i][j]);
//             printf("\n");
//         }
// }

/* Written from help of ChatGPT -> Giving corrct output */
#include <stdio.h>
#define MAX_ROWS 100
#define MAX_COLS 100
void matrix_multiply(int A[MAX_ROWS][MAX_COLS], int B[MAX_ROWS][MAX_COLS], int rowsA, int colsA, int rowsB, int colsB);
void main() {
    int matrix1[MAX_ROWS][MAX_COLS],matrix2[MAX_ROWS][MAX_COLS],row1,row2,col1,col2;
    printf("Enter the row and col for mat1\n");
    scanf("%d%d",&row1,&col1);
    printf("Enter the row and col for mat2\n");
    scanf("%d%d",&row2,&col2);
    printf("Enter the ele for mat1\n");
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) 
            scanf("%d", &matrix1[i][j]);
    }
    printf("Enter the ele for mat2\n");
    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col2; j++) 
            scanf("%d", &matrix2[i][j]);
    }
    matrix_multiply(matrix1, matrix2, row1, col1, row2, col2);
}
void matrix_multiply(int A[MAX_ROWS][MAX_COLS], int B[MAX_ROWS][MAX_COLS], int rowsA, int colsA, int rowsB, int colsB) {
    if (colsA != rowsB) {
        printf("Matrix multiplication not possible. Number of columns in first matrix must be equal to number of rows in second matrix.\n");
        return;
    }
    int result[MAX_ROWS][MAX_COLS];
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) 
                result[i][j] += A[i][k] * B[k][j];
        }
    }
    printf("Result of matrix multiplication:\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) 
            printf("%d ", result[i][j]);
        printf("\n");
    }
}
 