#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int value) {
    struct Node* newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    
    newNode->data = value;
    newNode->next = NULL;
    
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    
    printf("%d enqueued to queue\n", value);
}

void dequeue() {
    struct Node* temp;
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    
    temp = front;
    printf("%d dequeued from queue\n", front->data);
    front = front->next;
    
    if (front == NULL) {
        rear = NULL;
    }
    
    free(temp);
}

void display() {
    struct Node* temp;
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    
    temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value;
    clrscr();  // Clear screen in Turbo C
    
    while (1) {
        printf("\n---Queue Menu(Linked List)---\n");
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
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
