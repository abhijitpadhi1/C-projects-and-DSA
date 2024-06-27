#include<stdio.h>
struct Book{
    char title[20];
    char auther[20];
    int page;
    int price;
}b1;

void main(){
    struct Book b1;
    printf("Enter about the book\n");
    printf("Enter title of the book : ");
    gets(b1.title);
    printf("Enter the auther of the book : ");
    gets(b1.auther);
    printf("Enter page no the book : ");
    scanf("%d",&b1.page);
    printf("Enter the price of the book : ");
    scanf("%d",&b1.price);

    printf("the given book '%s' is written by '%s' having %d pages, has cost of %d.\n",b1.title,b1.auther,b1.page,b1.price);
}