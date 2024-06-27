//Program for check Palindrom
#include<stdio.h>
void main(){
    int n = 121,temp,x,sum=0;
    temp = n;
    while(!n==0){
        x = n%10;
        n = n/10;
        sum = sum*10+x;
    }
    if(sum==temp){
        printf("This is palendromic");
    }else{
    printf("This is not palendromic");
    }
}