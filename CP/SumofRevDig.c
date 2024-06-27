#include<stdio.h>
void main(){
    int row=4,col=4,sum=0;
    //printf("Enter the row and col of the matrix : ");
    //scanf("%d%d",&row,&col);
    int mat[4][4] = {{1,2,3,4},{1,2,3,4},{1,2,3,4},{1,2,3,4}};
    //printf("Enter the elements");
    /* for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            scanf("%d",&mat[i][j]);
        }
    } */
    printf("The given array is\n");
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
    for(int i=0,j=col-1;i<row,j>=0;i++,j--){
        sum += mat[i][j];
    }

    printf("\nThe sum of rev dig is %d",sum);
}