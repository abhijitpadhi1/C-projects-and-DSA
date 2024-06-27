// Implementation of Bubble sort

#include <stdio.h>
#define MAX 50

void bubbleSort(int arr[MAX], int n);
void inputArr(int arr[MAX], int size);
void dispArr(int arr[MAX], int size);

void main() {
    int arr[MAX], size;
    printf("Enter no of ele : ");
    scanf("%d", &size);
    printf("Emter ele for array\n");
    inputArr(arr, size);
    bubbleSort(arr, size);
    printf("The sorted array : ");
    dispArr(arr, size);
}

void bubbleSort(int arr[MAX], int size) {
    for(int i=0; i<size; i++) {
        for(int j=0; j<5-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }        
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