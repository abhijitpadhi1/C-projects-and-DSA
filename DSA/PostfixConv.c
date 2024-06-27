// Program for converting a infix expression to postfix expresion

# include <stdio.h>

# define MAX 50

char Stack[MAX];
int top = -1;

char* postfixConv (char* exp);
int presidence (char c);
void push(char value);
char pop();

void main () {
    char infix[MAX];
    printf("Ent infix exp : ");
    scanf("%s",infix);

    postfixConv (infix);
}

char* postfixConv (char* exp) {
    char pexp[MAX];
    int i, j;
    for (i=0, j=-1; exp[i]; ++i) {
        if ((exp[i]>='a' && exp[i]<='z')||(exp[i]>='A' && exp[i]<='Z')) {
            pexp[++j] = exp[i];
        } else if (exp[i] == ')') {
            while (top != -1 && Stack[top] != '(') {
                pexp[++j] = pop();
            }
            pop();
        } else if (exp[i] == '(') {
            push(exp[i]);
        } else {
            while(top != -1 && presidence(exp[i]) <= presidence(Stack[top])) {
                pexp[++j] = pop();
            }
            push(exp[i]);
        }
    }
    while (top != -1) {
        pexp[++j] = pop();
    }
    pexp[++j] = '\0';
    printf("Postfix : %s", pexp);
}

int presidence (char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
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