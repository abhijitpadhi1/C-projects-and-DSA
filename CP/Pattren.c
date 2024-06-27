// Programm for printing Patterns

#include<stdio.h>

void main()
{
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5-i;j++){
            printf(" ");
        }
        for(int j=1;j<=i;j++){
            printf("%d",j);
        }
        for(int j=i-1;j>=1;j--){
            
                printf("%d",j);
            
        }
        printf("\n");
    }
}