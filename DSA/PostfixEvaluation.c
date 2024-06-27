// Implementation of STACK by using of pointer

// #include <stdio.h>

// #define MAX_STACK_SIZE 100

// // Define the stack structure
// typedef struct {
//     int top;
//     int items[MAX_STACK_SIZE];
// } Stack;

// // Function prototypes
// void push(Stack *s, int value);
// int pop(Stack *s);
// int evaluatePostfix(char *expression);

// int main() {
//     char expression[100];
//     // Input the postfix expression
//     printf("Enter postfix expression: ");
//     scanf("%s", expression);
//     // Evaluate the postfix expression
//     int result = evaluatePostfix(expression);
//     printf("Result: %d\n", result);

//     return 0;
// }

// void push(Stack *s, int value) {
//     if (s->top == MAX_STACK_SIZE - 1) {
//         printf("Stack Overflow\n");
//         return;
//     } else {
//         s->items[++(s->top)] = value;
//     }
// }

// int pop(Stack *s) {
//     if (s->top == -1) {
//         printf("Stack Underflow\n");
//         return 0;
//     } else {
//         return s->items[(s->top)--];
//     }
// }

// int evaluatePostfix(char *expression) {
//     Stack s;
//     s.top = -1;

//     int i, operand1, operand2, result;
//     for (i = 0; expression[i] != '\0'; i++) {
//         if (expression[i]>='0' && expression[i]<='9') {
//             push(&s, expression[i] - '0');
//         } else {
//             operand2 = pop(&s);
//             operand1 = pop(&s);
//             switch (expression[i]) {
//                 case '+':
//                     push(&s, operand1 + operand2);
//                     break;
//                 case '-':
//                     push(&s, operand1 - operand2);
//                     break;
//                 case '*':
//                     push(&s, operand1 * operand2);
//                     break;
//                 case '/':
//                     push(&s, operand1 / operand2);
//                     break;
//                 default:
//                     printf("Invalid operator\n");
//                     break;
//             }
//         }
//     }
//     result = pop(&s);
//     return result;
// }


/* ############################################################################################ */



// Implementation of STACK with out using pointer

#include <stdio.h>

#define MAX 50

char Stack[MAX];
int top = -1;

void push(int value);
int pop();
int evaluatePostfix(char *expression);

void main() {
    char exp[100];
    // Input the Postfix exp
    printf("Enter exp to evaluate : ");
    scanf("%s", exp);
    //Evaluate the Postfix exp
    int res = evaluatePostfix(exp);
    printf("Result : %d\n", res);
}

int evaluatePostfix(char *exp) {
    int i, opnd1, opnd2, res;
    for(i=0; exp[i]!='\0'; i++) {
        if(exp[i]>='0' && exp[i]<='9') {
            push(exp[i]-'0');
        } else {
            opnd2 = pop();
            opnd1 = pop();
            switch(exp[i]) {
                case '+':
                    push(opnd1+opnd2);
                    break;
                case '-':
                    push(opnd1-opnd2);
                    break;
                case '*':
                    push(opnd1*opnd2);
                    break;
                case '/':
                    push(opnd1/opnd2);
                    break;
                default:
                    printf("Invalid");
                    break;
            }
        }
    }
    res = pop();
    return res;
}

void push(int val) {
    if(top == MAX-1) {
        printf("Stack Overflow!");
        return;
    } else {
        Stack[++top] = val;
    }
}

int pop() {
    if(top == -1) {
        printf("Stack Underflow!");
        return 0;
    } else {
        return Stack[top--];
    }
}