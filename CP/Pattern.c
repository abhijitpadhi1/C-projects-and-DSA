/* Program for printing the following 
    A
    A B
    A B C
    A B C D
    A B C D E
    A B C D E F      */

    #include<stdio.h>

    void main(){
        for(int i=1;i<=6;i++){
            char k='A';
            for( int j=1;j<=i;j++){
                //char k='A';
                printf("%c",k);
                k++;                
            }
            printf("\n");
        }
    }