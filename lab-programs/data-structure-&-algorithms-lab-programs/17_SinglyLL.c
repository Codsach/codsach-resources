#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;
Node* head = NULL;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertFront(int data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) return;

    newNode->next = head;
    head = newNode;
}

void insertRear(int data) {
    Node* newNode = createNode(data);
    Node* temp;
    if (newNode == NULL) return;

    if (head == NULL) {
        head = newNode;
        return;
    }
    temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void insertAtPosition(int data, int pos) {
    Node* newNode;
    Node* temp;
    int i;

    if (pos == 0) {
        insertFront(data);
        return;
    }
    newNode = createNode(data);
    if (newNode == NULL) return;

    temp = head;
    for (i = 0; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFront() {
    Node* temp;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    temp = head;
    head = head->next;
    free(temp);
}

void deleteRear() {
    Node* temp;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}

void deleteAtPosition(int pos) {
    Node* temp;
    Node* delNode;
    int i;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (pos == 0) {
        deleteFront();
        return;
    }
    temp = head;
    for (i = 0; i < pos - 1 && temp->next != NULL; i++)
        temp = temp->next;

    if (temp->next == NULL) {
        printf("Position out of range\n");
        return;
    }

    delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
}

void display() {
    Node* temp = head;

    if (temp == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void replaceAtPosition(int pos, int newvalue) {
    Node* temp;
    int i;

    temp = head;
    for (i = 0; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }
    temp->data = newvalue;
}

void swapNodes(int pos1, int pos2) {
    Node *prev1 = NULL, *curr1 = head;
    Node *prev2 = NULL, *curr2 = head;
    Node* temp;
    int i;

    if (pos1 == pos2)
        return;

    for (i = 0; curr1 != NULL && i < pos1; i++) {
        prev1 = curr1;
        curr1 = curr1->next;
    }

    for (i = 0; curr2 != NULL && i < pos2; i++) {
        prev2 = curr2;
        curr2 = curr2->next;
    }

    if (curr1 == NULL || curr2 == NULL) {
        printf("One or both Positions are out of range\n");
        return;
    }

    if (prev1 != NULL)
        prev1->next = curr2;
    else
        head = curr2;

    if (prev2 != NULL)
        prev2->next = curr1;
    else
        head = curr1;

    temp = curr1->next;
    curr1->next = curr2->next;
    curr2->next = temp;
}

int main() {
    int choice, data, pos, pos1, pos2;

    clrscr(); // For Turbo C screen clear

    while (1) {
        printf("\n---Singly Linked List Operations---\n");
        printf("1.Insert Front\n2.Insert Rear\n3.Insert at Position\n");
        printf("4.Delete Front\n5.Delete Rear\n6.Delete at Position\n");
        printf("7.Display\n8.Replace value\n9.Swap Nodes\n10.Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertFront(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertRear(data);
                break;
            case 3:
                printf("Enter Position and data: ");
                scanf("%d%d", &pos, &data);
                insertAtPosition(data, pos);
                break;
            case 4:
                deleteFront();
                break;
            case 5:
                deleteRear();
                break;
            case 6:
                printf("Enter Position: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Enter the Position and New value: ");
                scanf("%d%d", &pos, &data);
                replaceAtPosition(pos, data);
                break;
            case 9:
                printf("Enter Two Positions to Swap: ");
                scanf("%d%d", &pos1, &pos2);
                swapNodes(pos1, pos2);
                break;
            case 10:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}
