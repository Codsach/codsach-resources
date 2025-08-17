#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct {
    char arr[MAX];
    int top;
} Stack;

void push(Stack *stack, char op) {
    if (stack->top == MAX - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack->arr[++stack->top] = op;
}

char pop(Stack *stack) {
    if (stack->top == -1)
        return '#';  // Indicates empty stack
    return stack->arr[stack->top--];
}

char peek(Stack *stack) {
    if (stack->top == -1)
        return '#';  // Indicates empty stack
    return stack->arr[stack->top];
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

void infixToPostfix(char *expression) {
    int i, k = 0;
    char output[MAX];
    Stack stack;
    stack.top = -1;

    for (i = 0; i < strlen(expression); i++) {
        char ch = expression[i];

        if (isalnum(ch)) {
            output[k++] = ch;
        } else if (ch == '(') {
            push(&stack, ch);
        } else if (ch == ')') {
            while (stack.top != -1 && peek(&stack) != '(') {
                output[k++] = pop(&stack);
            }
            pop(&stack); // Remove '(' from stack
        } else {
            while (stack.top != -1 && precedence(peek(&stack)) >= precedence(ch)) {
                output[k++] = pop(&stack);
            }
            push(&stack, ch);
        }
    }

    while (stack.top != -1) {
        output[k++] = pop(&stack);
    }

    output[k] = '\0';
    printf("Postfix Expression: %s\n", output);
}

int main() {
    char expression[MAX];
    clrscr();

    printf("Enter an expression: ");
    scanf("%s", expression);

    printf("Infix Expression: %s\n", expression);
    infixToPostfix(expression);

    getch();
    return 0;
}
