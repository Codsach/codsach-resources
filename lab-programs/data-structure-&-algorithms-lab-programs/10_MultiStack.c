#include <stdio.h>
#include <conio.h>  // For clrscr() and getch()

#define MAX_STACKS 3
#define MAX_SIZE 100

typedef struct {
    int top;
    int arr[MAX_SIZE];
} stack;

void init(stack *s) {
    s->top = -1;
}

int isFull(stack *s) {
    return s->top == MAX_SIZE - 1;
}

int isEmpty(stack *s) {
    return s->top == -1;
}

void push(stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++(s->top)] = value;
}

int pop(stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

void display(stack *s) {
    int i;
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (i = 0; i <= s->top; i++) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int main() {
    int i;
    stack stacks[MAX_STACKS];
    int choice, stacknum, value;

    clrscr();

    for (i = 0; i < MAX_STACKS; i++) {
        init(&stacks[i]);
    }

    while (1) {
        printf("\n1. PUSH\n2. POP\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 4)
            break;

        printf("Enter stack number (0 to %d): ", MAX_STACKS - 1);
        scanf("%d", &stacknum);

        if (stacknum < 0 || stacknum >= MAX_STACKS) {
            printf("Invalid stack number!\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(&stacks[stacknum], value);
                break;

            case 2:
                value = pop(&stacks[stacknum]);
                if (value != -1) {
                    printf("Popped value: %d\n", value);
                }
                break;

            case 3:
                display(&stacks[stacknum]);
                break;

            default:
                printf("Invalid choice\n");
        }
    }

    printf("Program Terminated\n");
    getch();
    return 0;
}
