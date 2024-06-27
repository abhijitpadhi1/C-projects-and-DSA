// Program for implementation of Merge Sort in Array

# include <stdio.h>

# define MAX 99999

void merge (int arr[MAX], int firstIdx, int lastIdx, int midIdx);
void mergeSort (int arr[MAX], int firstIdx, int lastIdx);

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
    mergeSort(arr, 0, size-1);
    // Printing the sorted array
    printf("The sorted array : ");
    for (int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
}

void mergeSort (int arr[MAX], int firstIdx, int lastIdx) {
    if (firstIdx < lastIdx) {
        int midIdx = (firstIdx + lastIdx)/2;
        // Divide the array to two half
        mergeSort(arr, firstIdx, midIdx);
        mergeSort(arr, midIdx+1, lastIdx);
        // Merging the both arrays
        merge(arr, firstIdx, lastIdx, midIdx);
    }
}

void merge (int arr[MAX], int firstIdx, int lastIdx, int midIdx) {
    int i=0, j=0; // k=firstIdx;
    // Find the no of ele for two arrays
    int n1 = midIdx - firstIdx + 1;
    int n2 = lastIdx - midIdx;

    // Creating subarrays to store the eles 
    int arrL[n1+1], arrR[n2+1];
    for (int i=0; i<n1; i++) {
        arrL[i] = arr[firstIdx+i];
    }
    for (int j=0; j<n2; j++) {
        arrR[j] = arr[midIdx+1+j];
    }
    arrL[n1] = MAX, arrR[n2] = MAX;

    // Storing the both array with sorting to main array
    for (int k=firstIdx; k<=lastIdx; k++) {
        if (arrL[i] <= arrR[j]) {
            arr[k] = arrL[i];
            i++;
        } else {
            arr[k] = arrR[j];
            j++;
        }
    }
}