#include<stdio.h>
struct TIME
{
    int hr; int min; int sec;
}t1,t2;
struct TIME ADDTIME(struct TIME t1,struct TIME t2);
void main(){
    struct TIME t1,t2;
    printf("Enter the time in hour:min:sec format\n");
    scanf("%d",&t1.hr);
    scanf("%d",&t1.min);
    scanf("%d",&t1.sec);
    printf("Enter the time in hour:min:sec format\n");
    scanf("%d",&t2.hr);
    scanf("%d",&t2.min);
    scanf("%d",&t2.sec);
    struct TIME time = ADDTIME(t1,t2);
    printf("%d:%d:%d + %d:%d:%d = %d:%d:%d",t1.hr,t1.min,t1.sec,t2.hr,t2.min,t2.sec,time.hr,time.min,time.sec);
}
struct TIME ADDTIME(struct TIME t1,struct TIME t2){
    struct TIME time;
    time.hr = t1.hr+t2.hr;
    time.min = t1.min+t2.min;
    time.sec = t1.sec+t2.sec;
    if(time.sec>60){
        time.min = time.min+time.sec/60;
        time.sec = time.sec%60;
    }
    if(time.min>60){
        time.hr = time.hr+time.min/60;
        time.min = time.min%60;
    }
    return time;
}