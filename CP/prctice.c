#include<stdio.h>
#include<stdlib.h>
void main(){
    int *ptr;
    ptr = (int*) calloc(10,sizeof(int));
    if(ptr == NULL)
        printf("No");
    else{
        int *n,sum=0;
        for(n=ptr;n<ptr+10;n++)
            scanf("%d",n);
        for(n=ptr;n<ptr+10;n++)
            sum += *n;
        printf("sum=%d\n",sum);
    }
}