#include<stdio.h>
#include<math.h>

struct Point
{
    int Xco;
    int Yco;
}p1,p2;

void main(){
    struct Point p1,p2;
    printf("Enter the coordinates of first point\n");
    scanf("%d%d",&p1.Xco,&p1.Yco);
    printf("Enter the coordinates of second point\n");
    scanf("%d%d",&p2.Xco,&p2.Yco);

    printf("Distance between points %f",sqrt(pow(p2.Xco-p1.Xco,2)+pow(p2.Yco-p1.Yco,2)));
}