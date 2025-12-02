#include <stdio.h>
#define MAX 100

char stack[MAX];
int top = -1;


void push(char c) {
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = c;
}


char pop() {
    if (top == -1)
        return '\0';
    else
        return stack[top--];
}


int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void infixToPostfix(char infix[]) {
    char postfix[MAX];
    int j = 0;
    char c;

    for (int i = 0; infix[i] != '\0'; i++) {
        c = infix[i];


        if (isalnum(c)) {
            postfix[j++] = c;
        }

        else if (c == '(') {
            push(c);
        }

        else if (c == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();
            pop();
        }

        else {
            while (top != -1 && precedence(stack[top]) >= precedence(c))
                postfix[j++] = pop();
            push(c);
        }
    }


    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0'; // Null terminate the string

    printf("\nPostfix Expression: %s\n", postfix);
}

int main() {
    char infix[MAX];

    printf("Enter a valid parenthesized infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);

    return 0;
}

