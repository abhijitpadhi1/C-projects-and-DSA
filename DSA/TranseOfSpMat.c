// Program to find out the Transpose of any Sparse matrix. Input the Triplet matrix through the keyboard.

#include <stdio.h>

#define MAX 50

void findTranseSp(int tripSp[MAX][3]);
void dispTranseSp(int transeTripSp[MAX][3]);

void main() {
    int tripSp[MAX][3];
    int NoN;         // NoN -> No of NonZeros
    printf("Enter No of NonZero valus of SpMat : ");
    scanf("%d", &NoN);
    printf("Enter the triplate form of Sparse Matrix\n");
    for(int i=0; i<=NoN; i++) {
        for(int j=0; j<3; j++) {
            scanf("%d", &tripSp[i][j]);
        }
    }
    printf("The Inputed sparse matrix\n");
    dispTranseSp(tripSp);
    findTranseSp(tripSp);
}

//Calculating the triplate of transepose of given sparse matrix
void findTranseSp(int tripSp[MAX][3]) {
    int transeTripSp[MAX][3];
    int k=1;
    // Creating First row
    transeTripSp[0][0] = tripSp[0][1];
    transeTripSp[0][1] = tripSp[0][0];
    transeTripSp[0][2] = tripSp[0][2];
    // Updating to transepose matrix
    for(int i=0; i<tripSp[0][1]; i++) {
        for(int j=0; j<tripSp[0][0]; j++) {
            if(tripSp[j][1] == i) {
                transeTripSp[k][0] = tripSp[j][1];
                transeTripSp[k][1] = tripSp[j][0];
                transeTripSp[k][2] = tripSp[j][2];
                k++;
            }
        }
    }
    printf("The Transepose sparse matrix\n");
    dispTranseSp(transeTripSp);
}

// Converting the trip of transeSpMat to transeSpMat then display
void dispTranseSp(int transeTripSp[MAX][3]) {
    int spMat[MAX][MAX];
    for(int i=0; i<transeTripSp[0][0]; i++) {
        for(int j=0; j<transeTripSp[0][1]; j++) {
            spMat[i][j] = 0;
        }
    }
    // Updating zero to given non-zero
    for(int k=1; k<=transeTripSp[0][2]; k++) {
        spMat[transeTripSp[k][0]][transeTripSp[k][1]] = transeTripSp[k][2];
    }
    // Printing the spmat
    for(int i=0; i<transeTripSp[0][0]; i++) {
        for(int j=0; j<transeTripSp[0][1]; j++) {
            printf("%d ", spMat[i][j]);
        }
        printf("\n");
    }
}
