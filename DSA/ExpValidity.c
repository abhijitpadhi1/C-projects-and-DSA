// WAP to check the validity of any expression containing nested parenthesis using a stack.
// Implementation of STACK by using of pointer

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
// int checkExp(char exp[MAX]);
// int isPair(char ch1, char ch2);

// void main() {
//     char exp[MAX];
    
//     // Input exp to check
//     printf("Enter the expression to check : ");
//     scanf("%s", exp);
    
//     // Checking for validation
//     if(checkExp(exp)) {
//         printf("Expression is Balanced\n");
//     } else {
//         printf("Expression is Unbalanced\n");
//     }
// }

// int checkExp(char exp[MAX]) {
//     Stack s;
//     s.top = -1;

//     for(int i=0; exp[i] != '\0'; i++) {
//         if(exp[i] == '(') {
//             push(&s, exp[i]);
//         } else if(exp[i] == ')'){
//             if(s.top == -1){
//                 return 0;
//             } else if(!isPair(pop(&s), exp[i])) {
//                 return 0;
//             }
//         }
//     }
//     // Check stack is empty or not
//     if(s.top == -1) { 
//         return 1;
//     } else {
//         return 0;
//     }
// }

// int isPair(char ch1, char ch2) {
//     if(ch1=='(' && ch2==')') {
//         return 1;
//     } else {
//         return 0;
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




/* ############################################################################################## */



// Implementation of STACK with out using pointer

#include <stdio.h>

#define MAX 50

char Stack[MAX];
int top = -1;
  
void push(char val);
char pop();
int checkExp(char exp[MAX]);
int isPair(char ch1, char ch2);

void main() {
    char exp[MAX];
    
    // Input exp to check
    printf("Enter the expression to check : ");
    scanf("%s", exp);
    
    // Checking for validation
    if(checkExp(exp)) {
        printf("Expression is Balanced\n");
    } else {
        printf("Expression is Unbalanced\n");
    }
}

int checkExp(char exp[MAX]) {
    for(int i=0; exp[i] != '\0'; i++) {
        if(exp[i] == '(') {
            push(exp[i]);
        } else if(exp[i] == ')') {
            if(top == -1){
                return 0;
            } else if(!isPair(pop(), exp[i])) {
                return 0;
            }
        }
    }
    // Check stack is empty or not
    if(top == -1) { 
        return 1;
    } else {
        return 0;
    }
}

int isPair(char ch1, char ch2) {
    if(ch1=='(' && ch2==')') {
        return 1;
    } else {
        return 0;
    }
}

void push(char val) {
    if(top == MAX-1) {
        printf("Stack Ovreflow!");
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
        top--;
        return Stack[top+1];
    }
}