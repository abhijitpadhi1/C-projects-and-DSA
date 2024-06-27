// Implementation of Binary Search

#include <stdio.h>
#define MAX 50

void binarySearch(int arr[MAX], int size, int ele);
void inputArr(int arr[MAX], int size);
int checkSorted(int arr[MAX], int size);

void main() {
    int arr[MAX], size, ele;
    printf("Enter no of ele : ");
    scanf("%d", &size);
    printf("Emter ele for array\n");
    inputArr(arr, size);
    printf("Emter ele to search : ");
    scanf("%d", &ele);
    binarySearch(arr, size, ele);
}

void binarySearch(int arr[MAX], int size, int ele) {
    if(checkSorted(arr, size)) {
        int first=0, last=size-1, mid;
        while(first<=last) {
            mid = (first+last)/2;
            if(arr[mid] == ele) {
                printf("Ele is present\n");
                return;
            } else if(arr[mid] < ele) {
                first = mid+1;
            } else {
                last = mid-1;
            }
        }
        printf("Ele not found\n");
    } else {
        printf("Binary Search can not be implemented here!!!\n");
    }
}

int checkSorted(int arr[MAX], int size) {
    for(int i=0; i<size-1; i++) {
        if(arr[i] > arr[i+1]) {
            return 0;
        }
    }
    return 1;
}

void inputArr(int arr[MAX], int size) {
    for(int i=0; i<size; i++) {
        scanf("%d", &arr[i]);
    }
}
