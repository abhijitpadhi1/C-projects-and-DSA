#include<stdio.h>
#include<stdlib.h>
void main(){
    int *ptr,no;
    printf("Enter no of ele : ");
    scanf("%d",&no);
    ptr = (char*) malloc(no*sizeof(char));
    if(ptr == NULL){
        printf("No memory allocated");
    }else{
        int *n,ele;
        printf("Enter the ele for array\n");
        for(n=ptr;n<ptr+no;n++){
            scanf("%c",n);
        }

    }
}