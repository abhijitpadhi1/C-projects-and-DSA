// Implementation of Insertion sort

#include <stdio.h>
#define MAX 50

void insertionSort(int arr[MAX], int size);
void inputArr(int arr[MAX], int size);
void dispArr(int arr[MAX], int size);

void main() {
    int arr[MAX], size;
    printf("Enter no of ele : ");
    scanf("%d", &size);
    printf("Emter ele for array\n");
    inputArr(arr, size);
    insertionSort(arr, size);
    printf("The sorted array : ");
    dispArr(arr, size);
}

void insertionSort(int arr[MAX], int size) {
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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