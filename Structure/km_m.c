#include<stdio.h>
struct DISTANCE
{
    int kms;
    int meters;    
}d1,d2;

struct DISTANCE ADDDISTANCE(struct DISTANCE d1,struct DISTANCE d2);
void main(){
    struct DISTANCE d1,d2;
    printf("Enter the distane in kms and metres of first distance\n");
    scanf("%d",&d1.kms);
    scanf("%d",&d1.meters);
    printf("Enter the distane in kms and metres of second distance\n");
    scanf("%d",&d2.kms);
    scanf("%d",&d2.meters);
    struct DISTANCE dist = ADDDISTANCE(d1,d2);
    printf("(%dkms%dmeters)+(%dkms%dmeters)=(%dkms%dmeters)",d1.kms,d1.meters,d2.kms,d2.meters,dist.kms,dist.meters);
}
struct DISTANCE ADDDISTANCE(struct DISTANCE d1,struct DISTANCE d2){
    struct DISTANCE dist;
    dist.kms = d1.kms+d2.kms;
    dist.meters = d1.meters+d2.meters;
    if(dist.meters>1000){
        dist.kms = dist.kms+dist.meters/1000;
        dist.meters = dist.meters%1000;
    }
    return dist;
}