#include <stdio.h>
#include <conio.h>   // For getch()
#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
    } else {
        stack[++top] = c;
    }
}

char pop() {
    if (top == -1) {
        return '\0';
    } else {
        return stack[top--];
    }
}

int isBalanced(char *expression) {
    char ch, poppedChar;
    int i;

    for (i = 0; expression[i] != '\0'; i++) {
        ch = expression[i];

        if (ch == '(' || ch == '[' || ch == '{') {
            push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            poppedChar = pop();

            if ((ch == ')' && poppedChar != '(') ||
                (ch == ']' && poppedChar != '[') ||
                (ch == '}' && poppedChar != '{')) {
                return 0;
            }
        }
    }
    return (top == -1);
}

int main() {
    char expression[MAX];
    clrscr();

    printf("Enter a Mathematical Expression: ");
    scanf("%s", expression);

    if (isBalanced(expression)) {
        printf("The expression has balanced parentheses.\n");
    } else {
        printf("The expression does NOT have balanced parentheses.\n");
    }
    getch();
    return 0;
}
