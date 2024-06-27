// Program for find out the Triplet representation of any inputted Sparse matrix

#include <stdio.h>
#define MAX 50

void createSpMat(int spmat[MAX][MAX], int row, int col);
void convTripMat(int spmat[MAX][MAX], int row, int col);
void dispTrip(int tripMax[MAX][3]);

void main() {
    int spmat[MAX][MAX], tripmat[MAX][3], row, col;
    printf("Ent row : ");
    scanf("%d", &row);
    printf("Ent col : ");
    scanf("%d", &col);
    createSpMat(spmat,row,col);
    convTripMat(spmat,row,col);
}

void createSpMat(int spmat[MAX][MAX], int row, int col) {
    printf("Enter ele of Sparse matrix\n");
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            scanf("%d", &spmat[i][j]);
        }
    }
}

void convTripMat(int spmat[MAX][MAX], int row, int col) {
    int tripMat[MAX][3];
    int k=1;
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            if(spmat[i][j] != 0){
                tripMat[k][0] = i;
                tripMat[k][1] = j;
                tripMat[k][2] = spmat[i][j];
                k++;
            }
        }
    }
    tripMat[0][0] = row;
    tripMat[0][1] = col;
    tripMat[0][2] = k-1;
    dispTrip(tripMat);
}

void dispTrip(int tripMat[MAX][3]) {
    printf("Triplet representation\n");
    printf("(%d)Row (%d)Col (%d)val\n", tripMat[0][0], tripMat[0][1], tripMat[0][2]);
    for(int i=1; i<=tripMat[0][2]; i++) {
        for(int j=0; j<3; j++) {
            printf("%d ", tripMat[i][j]);
        }
        printf("\n");
    }
}
