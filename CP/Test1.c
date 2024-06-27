// Program for printing stars

#include<stdio.h>
void main(){
    for(int i=0;i<7;i++){
        for(int j=0;j<=1;j++){
            if((i+j)%2 == 0){
                if(i==3){
                    printf("#  *");
                }else{
                    printf("*");
                }
            }else{
                printf("  ");
            }
        }
        printf("\n");
    }
}