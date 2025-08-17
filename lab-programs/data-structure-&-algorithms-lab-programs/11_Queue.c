#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue Overflow! Cannot Insert %d\n", value);
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = value;
    printf("Enqueued %d\n", value);
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! Nothing to dequeue\n");
        return;
    }
    printf("Dequeued %d\n", queue[front++]);
    if (front > rear) {
        front = rear = -1;
    }
}

void display() {
    int i;
    if (front == -1) {
        printf("Queue is Empty!\n");
        return;
    }
    printf("Queue Elements: ");
    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;
    clrscr();

    while (1) {
        printf("\n----Queue Menu-----\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
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
                printf("Exiting Program.\n");
                getch();
                return 0;

            default:
                printf("Invalid Choice! Try Again.\n");
        }
    }
    return 0;
}
