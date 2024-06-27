#include<stdio.h>
struct Student
{
    char name[20];
    int roll;
    char branch[10];
    int CGPA;
};
void main(){
    struct Student st[5];
    for(int i=0;i<5;i++){
        printf("Enter about the student%d\n",i+1);
        printf("Enter full name : ");
        scanf("%s",st[i].name);
        printf("Enter roll : ");
        scanf("%d",&st[i].roll);
        printf("Enter branch : ");
        scanf("%s",st[i].branch);
        printf("Enter CGPA : ");
        scanf("%d",&st[i].CGPA);
    }
    int max=0;
    for(int i=0;i<5;i++){
        if(max<st[i].CGPA){
            max = st[i].CGPA;
        }
    }
    for(int i=0;i<5;i++){
        if(st[i].CGPA==max){
                printf("The required student is\nname : %s; roll : %d; branch : %s; CGPA : %d",st[i].name,st[i].roll,st[i].branch,st[i].CGPA);
        }
    }
}
