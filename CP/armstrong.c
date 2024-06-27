//Program for check Armstrong
#include<stdio.h>
void main(){
    int n = 135,temp,x,sum=0;
    temp = n;
    while(!n==0){
        x = n%10;
        n = n/10;
        sum = sum+(x*x*x);
    }
    if(sum==temp){
        printf("This is Armstrong");
    }else{
    printf("This is not Armstrong");
    }
}