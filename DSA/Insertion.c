#include<stdio.h>
void Sort(int arr[]){
    //int i=0,j=0,key;
    for(int j=1;j<5;j++){
        int key = arr[j];
        int i=j-1;
        while(i>=0 && arr[i]>=key){
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = key;
    }
    for(int k=0;k<5;k++)
        printf("%d ",arr[k]);
}
void main(){
    int arr[5];
    for(int i=0;i<5;i++)
        scanf("%d",&arr[i]);
    Sort(arr);
}