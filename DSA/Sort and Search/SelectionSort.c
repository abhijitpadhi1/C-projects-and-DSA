// Implementation of Selection sort

#include <stdio.h>
#define MAX 50

void selectionSort(int arr[MAX], int size);
void inputArr(int arr[MAX], int size);
void dispArr(int arr[MAX], int size);

void main() {
    int arr[MAX], size;
    printf("Enter no of ele : ");
    scanf("%d", &size);
    printf("Emter ele for array\n");
    inputArr(arr, size);
    selectionSort(arr, size);
    printf("The sorted array : ");
    dispArr(arr, size);
}

void selectionSort(int arr[], int size) {
    int i, j, idx;
    for (i = 0; i<size-1; i++) {
        idx = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[idx]) {
                idx = j;
            }
        }
        int temp = arr[idx];
        arr[idx] = arr[i];
        arr[i] = temp;
    }
}

void inputArr(int arr[MAX], int size) {
    for(int i=0; i<size; i++) {
        scanf("%d", &arr[i]);
    }
}

void dispArr(int arr[MAX], int size) {
    for(int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
}