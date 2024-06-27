#include<stdio.h>
#include<stdlib.h>
void main(){
    int *ptr;
    ptr = (int*) malloc(10*sizeof(int));
    if(ptr == NULL){
        printf("No memory allocated");
    }else{
        int *n,sum = 0;
        printf("Enter 10 ele for array\n");
        for(n=ptr;n<ptr+10;n++){
            scanf("%d",n);
        }
        for(n=ptr;n<ptr+10;n++){
            sum += *n;
        }
        printf("The sum of array is : %d",sum);
        
    }
}