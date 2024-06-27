//LARGEST ELEMENT
#include<stdio.h>
int findLargest(int arr[],int n);
void main(){
    int n;
    printf("Enter the no of element : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements for array\n");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Largest Element is : %d",findLargest(arr,n));
}
int findLargest(int arr[],int n){
    int large=0;
    for(int i=0;i<n;i++){
        if(arr[i]>large)
            large = arr[i];
    }
    return large;
}