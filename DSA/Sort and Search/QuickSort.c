// Program for implementation of Quick Sort in array

# include <stdio.h>

# define MAX 99999

int partition (int arr[MAX], int firstIdx, int lastIdx);
void quickSort (int arr[MAX], int firstIdx, int lastIdx);

void main () {
    int arr[MAX];
    int size;
    
    // Input of Unsorted array 
    printf("Ent size : ");
    scanf("%d", &size);
    printf("Ent ele :\n");
    for (int i=0; i<size; i++) {
        scanf("%d", &arr[i]);
    }
    // For sorting of array
    quickSort(arr, 0, size-1);
    // Printing the sorted array
    printf("The sorted array : ");
    for (int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
}

void quickSort (int arr[MAX], int firstIdx, int lastIdx) {
    if (firstIdx < lastIdx) {
        int pi = partition(arr, firstIdx, lastIdx);
        // Call quickSort() in both side of the pivote 
        quickSort(arr, firstIdx, pi-1);
        quickSort(arr, pi+1, lastIdx);
    }
}

int partition (int arr[MAX], int firstIdx, int lastIdx) {
    int temp;
    // Make the last idx ele as pivote
    int pi = arr[lastIdx];
    int i = firstIdx-1;
    // Swap the smaller ele then pivote to left of it
    for (int j=firstIdx; j<lastIdx; j++) {
        if (arr[j] <= pi) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Swap the pivote between smaller and larger
    temp = arr[i+1];
    arr[i+1] = arr[lastIdx];
    arr[lastIdx] = temp;
    // Return the idx of pivote
    return i+1;
}