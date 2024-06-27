#include<stdio.h>
#include<stdlib.h>

void main(){
    int *ptr,no;
    printf("Enter no of ele : ");
    scanf("%d",&no);
    ptr = (int*) malloc(no*sizeof(int));
    
    if(ptr == NULL) {
        printf("No memory allocated");
    } else {
        int *n,ele;
        printf("Enter the ele for array\n");
        for(n=ptr;n<ptr+no;n++) {
            scanf("%d",n);
        }

        printf("Enter the ele to check : ");
        scanf("%d",&ele);
        for(n=ptr;n<ptr+no;n++) {
            if(ele == *n) {
                printf("The wanted ele is present");
                break;
            }
        }
        if(n==ptr+no) {
            printf("The wanted ele is not present");
        }
        printf("\n");
        
    }
}