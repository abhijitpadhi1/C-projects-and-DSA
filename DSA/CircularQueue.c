// // Implementation of QUEUE with out using pointer

// #include<stdio.h>

// #define MAX 5

// int que[MAX];
// int front = -1, rare = -1;

// void enqueue(int ele);
// int dequeue();
// void disp();

// void main() {
//     int ch = 0;
//     while(ch != 4) {
//         int ele;
//         printf("1:insert\t2:delete\t3:traverse\t4:exit\n");
//         scanf("%d",&ch);
//         switch(ch) {
//             case 1:
//                 printf("Ent ele : ");
//                 scanf("%d",&ele);
//                 enqueue(ele);
//                 break;
//             case 2:
//                 printf("Front ele %d\n",dequeue());
//                 break;
//             case 3:
//                 disp();
//                 break;
//             case 4:
//                 printf("Exited\n");
//                 break;
//             default:
//                 printf("Wrong chcoice\n");
//                 break;
//         }
//     }
// }

// void enqueue(int ele) {
//     if((front == 0 && rare == MAX-1) || (rare == (front-1 % MAX-1))) {
//         printf("Queue is full\n");
//         return;
//     } else {
//         if(front == -1 && rare == -1) {
//             front++; rare++;
//             que[rare] = ele;
//         } else if(front != 0 && rare == MAX-1) {
//             rare = 0;
//             que[rare] = ele;
//         } else {
//             rare++;
//             que[rare] = ele;
//         }
//     }
// }

// int dequeue() {
//     if(front == -1) {
//         printf("Queue is empty\n");
//         return -1;
//     } else {
//         int ele = que[front];
//         if(front == rare) {
//             front = -1;
//             rare = -1;
//         } else if(front == MAX-1) {
//             front = 0;
//         } else {
//             front++;
//         }
//         return ele;
//     }
// }

// void disp() {
//     if(front == -1 && rare == -1) {
//         printf("Queue is Empty\n");
//         return;
//     } else {
//         printf("Queue ele : ");
//         if(rare >= front) {
//             for(int i=front; i<=rare; i++) {
//                 printf("%d ", que[i]);
//             }
//         } else {
//             for(int i=front; i<MAX; i++) {
//                 printf("%d ", que[i]);
//             }
//             for(int i=0; i<=rare; i++) {
//                 printf("%d ", que[i]);
//             }
//         }
//         printf("\n");
//     }
// }



/* ################################################################################################ */



// Implementation of QUEUE by using of pointer

#include <stdio.h>

#define MAX_QUEUE_SIZE 5

typedef struct {
    int front;
    int rare;
    int items[MAX_QUEUE_SIZE];
} CQueue;

void enqueue(CQueue *cq, int ele);
int dequeue(CQueue *cq);
void disp(CQueue *cq);

int main() {
    CQueue cq;
    cq.front = -1;
    cq.rare = -1;
    
    int ch = 0;
    while(ch != 4) {
        int ele;
        printf("1:insert\t2:delete\t3:traverse\t4:exit\n");
        scanf("%d",&ch);
        switch(ch) {
            case 1:
                printf("Ent ele : ");
                scanf("%d",&ele);
                enqueue(&cq,ele);
                break;
            case 2:
                printf("Front ele %d\n",dequeue(&cq));
                break;
            case 3:
                disp(&cq);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Wrong chcoice\n");
                break;
        }
    }
    
    return 0;
}

void enqueue(CQueue *cq, int ele) {
    if((cq->rare==MAX_QUEUE_SIZE-1 && cq->front==0) || (cq->rare==(cq->front-1 % MAX_QUEUE_SIZE-1))) {
        printf("Queue Overflow!\n");
        return;
    } else {
        if(cq->front == -1 && cq->rare == -1) {
            cq->front = cq->rare = 0;
            cq->items[cq->rare] = ele;
        } else if(cq->front!=0 && cq->rare==MAX_QUEUE_SIZE-1) {
            cq->rare = 0;
            cq->items[cq->rare] = ele;
        } else {
            cq->rare++;
            cq->items[cq->rare] = ele;
        }
    }
}

int dequeue(CQueue *cq) {
    if(cq->front == -1) {
        printf("Queue Underflow!\n");
        return -1;
    } else {
        int ele = cq->items[cq->front];
        if(cq->front == cq->rare) {
            cq->front = cq->rare = -1;
        } else if(cq->front == MAX_QUEUE_SIZE-1) {
            cq->front = 0;
        } else {
            cq->front++;
        }
        return ele;
    }
}

void disp(CQueue *cq){
    if(cq->front == -1 && cq->rare == -1) {
        printf("Queue is Empty\n");
        return;
    } else {
        printf("Queue ele : ");
        if(cq->front <= cq->rare) {
            for(int i=cq->front; i<=cq->rare; i++) {
                printf("%d ",cq->items[i]);
            }
        } else {
            for(int i=cq->front; i<=MAX_QUEUE_SIZE-1; i++) {
                printf("%d ",cq->items[i]);
            }
            for(int i=0; i<=cq->rare; i++) {
                printf("%d ",cq->items[i]);
            }
        }
        printf("\n");
    }
}