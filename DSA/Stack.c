/* // Implementation of STACK with out using pointer

#include<stdio.h>
#define MAX 50

int Stack[MAX], top=-1;

void push(int val);
int pop();
void traverse();

void main() {
    int ch = 0;
    while(ch != 4) {
        int ele;
        printf("1:push\t2:pop\t3:traverse\t4:exit\n");
        scanf("%d",&ch);
        switch(ch) {
            case 1:
                printf("Ent ele : ");
                scanf("%d",&ele);
                push(ele);
                break;
            case 2:
                printf("topmost %d\n",pop());
                break;
            case 3:
                traverse();
                break;
            case 4:
                printf("Exiting...");
                break;
            default:
                printf("Wrong chcoice\n");
                break;
        }
    }
}

void push(int val) {
    if(top == MAX-1) {
        printf("Stack Overflow\n");
        return;
    } else {
        top++;
        Stack[top] = val;
    }
}

int pop() {
    if(top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        top--;
        return Stack[top+1];
    }
}

void traverse() {
    if(top == -1) {
        printf("Empty Stack\n");
    } else {
        printf("Top to Bottom : ");
        for(int i=top;i>=0;i--) {
            printf("%d ",Stack[i]);
        }
        printf("\n");
    }
}  */



/* ###################################################################################### */



// Implementation of STACK by using of pointer

#include <stdio.h>

#define MAX_STACK_SIZE 50

// Define the Stack structure
typedef struct {
    int top;
    int items[MAX_STACK_SIZE];
} Stack;

// Function prototypes
void push(Stack *s, int ele);
int pop(Stack *s);
void traverse(Stack *s);

void main() {
    Stack s;
    s.top = -1;

    int ch = 0;
    while(ch != 4) {
        int ele;
        printf("1:push\t2:pop\t3:traverse\t4:exit\n");
        scanf("%d",&ch);
        switch(ch) {
            case 1:
                printf("Ent ele : ");
                scanf("%d",&ele);
                push(&s, ele);
                break;
            case 2:
                printf("topmost %d\n",pop(&s));
                break;
            case 3:
                traverse(&s);
                break;
            case 4:
                printf("Exiting...");
                break;
            default:
                printf("Wrong chcoice\n");
                break;
        }
    }
}

void push(Stack *s, int ele) {
    if(s->top == MAX_STACK_SIZE-1) {
        printf("Stack Overflow!");
        return;
    } else {
        s->items[++(s->top)] = ele;
    }
}

int pop(Stack *s) {
    if(s->top == -1) {
        printf("Stack Underflow!");
        return -1;
    } else {
        return s->items[(s->top)--];
    }
}

void traverse(Stack *s) {
    if(s->top == -1) {
        printf("Empty Stack\n");
        return;
    } else {
        printf("Top to Bottom : ");
        for(int i=s->top; i>-1; i--) {
            printf("%d ", s->items[i]);
        }
        printf("\n");
    }
}