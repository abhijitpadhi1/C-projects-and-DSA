// 1. WAP a program to delete an element from a desire position given by user using array

// #include<stdio.h>

// void main(){
//     int n,pos,arr[50];
    
//     printf("Enter size : ");
//     scanf("%d",&n);
//     printf("Enter elments of array\n");
//     for (int i=0; i<n; i++) {
//         scanf("%d",&arr[i]);
//     }
    
//     printf("Enter the pos to remove : ");
//     scanf("%d",&pos);

//     if(pos>=1 && pos<=n+1) {
//         for (int i=pos-1; i<n-1; i++) {
//             arr[i]=arr[i+1];
//         }

//         printf("The array after Deletion : ");
//         for (int i=0; i<n-1; i++) {
//             printf("%d ",arr[i]);
//         }
//     } else {
//         printf("the inputed position is invalid\n");
//     }
    
// }


// 2. WAP a program to insert an element from a desire position given by user using array

// #include<stdio.h>
// void main(){
//     int ele,size,pos,arr[100];

//     printf("Enter size : ");
//     scanf("%d",&size);
//     printf("Enter elments of array\n");
//     for(int i=0; i<size; i++) {
//         scanf("%d",&arr[i]);
//     }

//     printf("Enter position to insert : ");
//     scanf("%d",&pos);
//     printf("enter the element : ");
//     scanf("%d",&ele);

//     if(pos>=1 && pos<=size+1) {
//         for(int i=size-1; i>=pos-1; i--) {
//             arr[i+1] = arr[i];
//         }
//         arr[pos-1] = ele;
        
//         printf("The array after Insertion : ");
//         for(int i=0; i<size+1; i++) {
//             printf("%d ",arr[i]);
//         }
//     } else {
//         printf("the inputed position is invalid\n");
//     }
// }


// // 3. WAP a program to delete an element from a desire position given by user using array

// #include<stdio.h>

// void main(){
//     int n1,n2,arr1[50],arr2[50],res[100];
    
//     printf("Enter size of array1 : ");
//     scanf("%d",&n1);
//     printf("Enter elments of array1\n");
//     for (int i=0; i<n1; i++) {
//         scanf("%d",&arr1[i]);
//     }

//     printf("Enter size of array2 : ");
//     scanf("%d",&n2);
//     printf("Enter elments of array2\n");
//     for (int i=0; i<n2; i++) {
//         scanf("%d",&arr2[i]);
//     }
    
//     for(int i=0; i<n1; i++) {
//         res[i] = arr1[i];
//     }
//     for(int i=n1,j=0; i<n1+n2,j<n2; i++,j++) {
//         res[i] = arr2[j];
//     }

//     printf("Resulting array aftet merging : ");
//     for(int i=0; i<n1+n2; i++) {
//         printf("%d ", res[i]);
//     }
// }


// // 4. WAP to find out the sum of the elements of an array using a function.

// #include<stdio.h>

// int findSum(int arr[],int n);

// void main(){
//     int n,arr[50];
//     printf("Enter size : ");
//     scanf("%d", &n);

//     printf("Enter the elements for array\n");
//     for(int i=0; i<n; i++) {
//         scanf("%d", &arr[i]);
//     }
        
//     printf("Sum of Elements : %d", findSum(arr,n));
// }

// int findSum(int arr[],int n) {
//     int sum = 0;
//     for(int i=0; i<n; i++){
//         sum += arr[i];
//     }
//     return sum;
// }


// // 5. WAP to find the largest element of an array using a function.

// #include<stdio.h>

// int findLargest(int arr[],int n);

// void main(){
//     int n,arr[50];

//     printf("Enter size : ");
//     scanf("%d", &n);
//     printf("Enter the elements for array\n");
//     for(int i=0; i<n; i++) {
//         scanf("%d", &arr[i]);
//     }
    
//     printf("Largest Element is : %d", findLargest(arr,n));
// }

// int findLargest(int arr[],int n){
//     int large = 0;
    
//     for(int i=0; i<n; i++) {
//         if(arr[i]>large) {
//             large = arr[i];
//         }
//     }

//     return large;
// }

// // 6. WAP to find out the transpose of any matrix using a function.

// #include <stdio.h>

// #define MAX 50

// void findTranse(int row, int col, int mat[MAX][MAX]);

// void main() {
//     int row, col, mat[MAX][MAX];

//     printf("Enter the row and col for matrix1\n");
//     scanf("%d%d", &row, &col);
//     printf("Enter the ele for matrix1\n");
//     for (int i=0; i<row; i++) {
//         for (int j=0; j<col; j++) {
//             scanf("%d", &mat[i][j]);
//         } 
//     }

//     findTranse(row, col, mat);
// }

// void findTranse(int row, int col, int mat[MAX][MAX]) {
//     int transeMat[MAX][MAX];

//     for(int i=0; i<col; i++) {
//         for(int j=0; j<row; j++) {
//             transeMat[i][j] = mat[j][i];
//         }
//     }

//     printf("Transepose of given matrix:\n");
//     for (int i=0; i<col; i++) {
//         for (int j=0; j<row; j++) {
//             printf("%d ", transeMat[i][j]);
//         }
//         printf("\n");
//     }
// }

// // 7. WAP to multiply two matrices using a function. Check all necessary conditions for matrix multiplication.

// #include <stdio.h>

// #define MAX_ROWS 100
// #define MAX_COLS 100

// void matrix_multiply(int A[MAX_ROWS][MAX_COLS], int B[MAX_ROWS][MAX_COLS], int rowsA, int colsA, int rowsB, int colsB);

// void main() {
//     int matrix1[MAX_ROWS][MAX_COLS], matrix2[MAX_ROWS][MAX_COLS], row1, row2, col1, col2;
    
//     printf("Enter the row and col for matrix1\n");
//     scanf("%d%d", &row1, &col1);
//     printf("Enter the ele for matrix1\n");
//     for (int i=0; i<row1; i++) {
//         for (int j=0; j<col1; j++) {
//             scanf("%d", &matrix1[i][j]);
//         } 
//     }

//     printf("Enter the row and col for matrix2\n");
//     scanf("%d%d", &row2, &col2);
//     printf("Enter the ele for matrix2\n");
//     for (int i=0; i<row2; i++) {
//         for (int j=0; j<col2; j++) {
//             scanf("%d", &matrix2[i][j]);
//         }
//     }

//     matrix_multiply(matrix1, matrix2, row1, col1, row2, col2);
// }

// void matrix_multiply(int A[MAX_ROWS][MAX_COLS], int B[MAX_ROWS][MAX_COLS], int rowsA, int colsA, int rowsB, int colsB) {
//     if (colsA != rowsB) {
//         printf("Matrix multiplication not possible. Number of columns in first matrix must be equal to number of rows in second matrix.\n");
//         return;
//     }

//     int result[MAX_ROWS][MAX_COLS];
    
//     for (int i=0; i<rowsA; i++) {
//         for (int j=0; j<colsB; j++) {
//             result[i][j] = 0;
//             for (int k=0; k<colsA; k++) {
//                 result[i][j] += A[i][k] * B[k][j];
//             }
//         }
//     }

//     printf("Result of matrix multiplication:\n");
//     for (int i=0; i<rowsA; i++) {
//         for (int j=0; j<colsB; j++) {
//             printf("%d ", result[i][j]);
//         }
//         printf("\n");
//     }
// }
