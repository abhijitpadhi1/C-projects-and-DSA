// Program for implementation of HeapSort

# include <stdio.h>

# define MAX 99999

void heapSort (int arr[MAX], int n);
void heapify (int arr[MAX], int n, int i);

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
    heapSort(arr, size);
    // Printing the sorted array
    printf("The sorted array : ");
    for (int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
}

void heapSort(int arr[MAX], int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end, then swap(arr[0], arr[i]);
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void heapify(int arr[MAX], int n, int i) {
    int largest = i;            // Initialize largest as root
    int left = 2 * i + 1;       // left child
    int right = 2 * i + 2;      // right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    
    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]){
        largest = right;
    }

    // If largest is not root, swap the node with largest one 
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
