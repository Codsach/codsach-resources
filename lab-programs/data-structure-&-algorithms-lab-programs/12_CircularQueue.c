#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int regNo;
    char course[50];
    int year;
} student;

student queue[MAX];
int front = -1, rear = -1;

int isFull() {
    return (front == (rear + 1) % MAX);
}

int isEmpty() {
    return (front == -1);
}

void enqueue(student s) {
    if (isFull()) {
        printf("\nQueue is Full! Cannot insert.\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = s;
    printf("\nStudent Data Inserted Successfully.\n");
}

void dequeue() {
    if (isEmpty()) {
        printf("\nQueue is Empty! Cannot delete.\n");
        return;
    }

    printf("\nDeleted Student data with Reg No: %d\n", queue[front].regNo);

    if (front == rear) {
        // Queue becomes empty after removing last element
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void display() {
    int i;
    if (isEmpty()) {
        printf("\nQueue is Empty\n");
        return;
    }

    printf("\nStudents in Circular Queue:\n");
    i = front;
    while (1) {
        printf("Reg No: %d | Course: %s | Year: %d\n",
               queue[i].regNo, queue[i].course, queue[i].year);

        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
}

int main() {
    int choice;
    student s;

    clrscr();

    while (1) {
        printf("\n-- Circular Queue Menu --\n");
        printf("1. Enqueue Student\n");
        printf("2. Dequeue Student\n");
        printf("3. Display Students\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline left by scanf

        switch (choice) {
            case 1:
                printf("Enter Registration Number: ");
                scanf("%d", &s.regNo);
                getchar();

                printf("Enter course title: ");
                fgets(s.course, sizeof(s.course), stdin);
                s.course[strcspn(s.course, "\n")] = '\0'; // Remove trailing newline

                printf("Enter Year: ");
                scanf("%d", &s.year);
                enqueue(s);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting Program\n");
                getch();
                exit(0);

            default:
                printf("Invalid Choice! Try Again\n");
        }
    }

    return 0;
}
