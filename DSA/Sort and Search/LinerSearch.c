// Implementation of Linear Search

#include <stdio.h>
#define MAX 50

void linearSearch(int arr[MAX], int size, int ele);
void inputArr(int arr[MAX], int size);
void dispArr(int arr[MAX], int size);

void main() {
    int arr[MAX], size, ele;
    printf("Enter no of ele : ");
    scanf("%d", &size);
    printf("Emter ele for array\n");
    inputArr(arr, size);
    printf("Emter ele to search : ");
    scanf("%d", &ele);
    linearSearch(arr, size, ele);
}

void linearSearch(int arr[MAX], int size, int ele) {
    int i;
    for (i=0; i<size; i++) {
        if(arr[i] == ele) {
            printf("The req ele is present at %d pos\n", i+1);
            return;
        }
    }
    if(i == size) {
        printf("The req ele is not present\n");
        return;
    }
}

void inputArr(int arr[MAX], int size) {
    for(int i=0; i<size; i++) {
        scanf("%d", &arr[i]);
    }
}
