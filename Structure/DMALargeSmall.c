#include<stdio.h>
#include<stdlib.h>

void main(){
    int *ptr,no;
    printf("Enter the no of ele : ");
    scanf("%d",&no);
    ptr = (int*) malloc(no*sizeof(int));
    
    if(ptr == NULL) {
        printf("No memory allocated");
    } else {
        int *n,max=0,min;
        printf("Enter the ele for array\n");
        for(n=ptr;n<ptr+no;n++) {
            scanf("%d",n);
        }
        
        for(n=ptr;n<ptr+no;n++) {
            if(*n>max) {
                max = *n;
            }
            if(*n<min) {
                min = *n;
            }
        }
        printf("The smallest is %d and largest is %d \n",min,max);
        
    }
}