#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int value) {
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d pushed to stack\n", value);
}

void pop() {
    struct Node* temp;
    if (top == NULL) {
        printf("Stack is Empty!\n");
        return;
    }
    
    temp = top;
    printf("%d Popped from stack\n", top->data);
    top = top->next;
    free(temp);
}

void display() {
    struct Node* temp;
    if (top == NULL) {
        printf("Stack is Empty!\n");
        return;
    }
    
    temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value;
    clrscr();
    
    while (1) {
        printf("\n---Stack Menu(Linked List)---\n");
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice! Try Again\n");
        }
    }
    
    return 0;
}
