#include<stdio.h>
struct EMPLOYEE
{
    char name[30];
    char empid[20];
    char department[10];
    int age;
    int salary;    
};

void main(){
    struct EMPLOYEE emp[5];
    for(int i=0;i<5;i++){
        printf("Enter about the employee%d\n",i+1);
        printf("Enter name : ");
        gets(emp[i].name);
        printf("Enter the employee id : ");
        gets(emp[i].empid);
        printf("Enter department : ");
        gets(emp[i].department);
        printf("Enter age : ");
        scanf("%d",&emp[i].age);
        printf("Enter salary : ");
        scanf("%d",&emp[i].salary);
    }

    printf("The given Employee data is\n");
    for(int i=0;i<5;i++){
        printf("name : %s; id : %s; department : %s ;age : %d; salary : %d\n",emp[i].name,emp[i].empid,emp[i].department,emp[i].age,emp[i].salary);
    }
}