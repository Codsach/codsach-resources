#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <conio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        exit(1);
    }
    stack[++top] = value;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    return stack[top--];
}

int evaluatePostfix(char *expr) {
    int i = 0;
    char ch;
    int op1, op2, result;

    while ((ch = expr[i++]) != '\0') {
        if (isdigit(ch)) {
            push(ch - '0');
        } else {
            op2 = pop();
            op1 = pop();

            switch (ch) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/':
                    if (op2 == 0) {
                        printf("Division by zero error!\n");
                        exit(1);
                    }
                    result = op1 / op2;
                    break;
                default:
                    printf("Invalid Operator %c \n", ch);
                    exit(1);
            }
            push(result);
        }
    }
    return pop();
}

int main() {
    char postfix[MAX];
    int result;

    clrscr();

    printf("Enter postfix Expression (e.g.. 53+82-*): ");
    scanf("%s", postfix);

    result = evaluatePostfix(postfix);

    printf("Result = %d\n", result);

    getch();
    return 0;
}
