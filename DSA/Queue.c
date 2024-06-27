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
//                 printf("Exiting...");
//                 break;
//             default:
//                 printf("Wrong chcoice\n");
//                 break;
//         }
//     }
// }

// void enqueue(int ele) {
//     if(rare == MAX-1) {
//         printf("Queue is full\n");
//         return;
//     } else {
//         if(front == -1 && rare == -1) {
//             front++; rare++;
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
//             rare = front = -1;
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
//         printf("Front to Rare : ");
//         for(int i=front; i<=rare; i++) {
//             printf("%d ", que[i]);
//         }
//         printf("\n");
//     }
// }



/* ##################################################################################################### */


// Implementation of QUEUE by using of pointer

#include <stdio.h>

#define MAX_QUEUE_SIZE 5

typedef struct {
    int front;
    int rare;
    int items[MAX_QUEUE_SIZE];
} Queue;

void enqueue(Queue *q, int ele);
int dequeue(Queue *q);
void disp(Queue *q);

int main() {
    Queue q;
    q.front = -1;
    q.rare = -1;
    
    int ch = 0;
    while(ch != 4) {
        int ele;
        printf("1:insert\t2:delete\t3:traverse\t4:exit\n");
        scanf("%d", &ch);
        switch(ch) {
            case 1:
                printf("Ent ele : ");
                scanf("%d", &ele);
                enqueue(&q,ele);
                break;
            case 2:
                printf("Front ele : %d\n", dequeue(&q));
                break;
            case 3:
                disp(&q);
                break;
            case 4:
                printf("Exiting...");
                break;
            default:
                printf("Wrong choice\n");
                break;
        }
    }
    
    return 0;
}

void enqueue(Queue *q, int ele) {
    if(q->rare == MAX_QUEUE_SIZE-1) {
        printf("Queue Overflow!\n");
        return;
    } else {
        if(q->front==-1 && q->rare == -1) {
            q->front = q->rare += 1;
            q->items[q->rare] = ele; 
        } else {
            q->items[++(q->rare)] = ele;
        }
    }
}

int dequeue(Queue *q) {
    if(q->front == -1) {
        printf("Queue Underflow!\n");
        return -1;
    } else {
        int ele = q->items[q->front];
        if(q->rare == q->front) {
            q->front = q->rare = -1;
        } else {
            q->front++;
        }
        return ele;
    }
}

void disp(Queue *q) {
    if(q->front == q->rare == -1) {
        printf("Queue is empty\n");
        return;
    } else {
        printf("Front to Rare : ");
        for(int i=q->front; i<=q->rare; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}