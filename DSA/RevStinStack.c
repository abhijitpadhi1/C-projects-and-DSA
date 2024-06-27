// // Implementation of STACK by using of pointer

// #include<stdio.h>

// #define MAX 50

// // Define the stack structure
// typedef struct {
//     int top;
//     char items[MAX];
// } Stack;

// // Function prototypes
// void push(Stack *s, char val);
// char pop(Stack *s);
// void revSt(char st[MAX]);

// void main() {
//     // Input the String to Reverse
//     char st[MAX];
//     printf("Ent St : ");
//     scanf("%s",st);
//     revSt(st);
// }

// void revSt(char st[MAX]) {
//     Stack s;
//     s.top = -1;
//     char revst[MAX];
//     int i,j=0;
//     // Converting the string to its reverse form
//     for(i=0; st[i] != '\0'; i++) {
//         push(&s,st[i]);
//     }
//     printf("Rev st : ");
//     while(s.top != -1){
//         revst[j] = pop(&s);
//         printf("%c",revst[j]);
//         j++;
//     }
// }

// void push(Stack *s, char val) {
//     if(s->top == MAX-1) {
//         printf("Stack Overflow\n");
//         return;
//     } else {
//         s->items[++(s->top)] = val;
//     }
// }

// char pop(Stack *s) {
//     if(s->top == -1) {
//         printf("Stack Underflow\n");
//         return -1;
//     } else {
//         return s->items[(s->top)--];
//     }
// }



/* ########################################################################################## */



// Implementation of STACK with out using pointer

#include <stdio.h>

#define MAX 50

char Stack[MAX];
int top = -1;

void revSt(char st[MAX]);
void push(char val);
char pop();

void main() {
    // Input the String to Reverse
    char st[MAX];
    printf("Ent St : ");
    scanf("%s",st);
    revSt(st);
}

void revSt(char st[MAX]) {
    char revst[MAX];
    int i,j=0;
    // Converting the String to rev
    for(i=0; st[i]!='\0';i++) {
        push(st[i]);
    }
    printf("Rev st : ");
    while(top!=-1) {
        revst[j] = pop();
        printf("%c",revst[j]);
        j++;
    }
}

void push(char val) {
    if(top == MAX-1) {
        printf("Stack Overflow!");
        return;
    } else {
        top++;
        Stack[top] = val;
    }
}

char pop() {
    if(top == -1) {
        printf("Stack Underflow!");
        return -1;
    } else {
        return Stack[top--];
    }
}