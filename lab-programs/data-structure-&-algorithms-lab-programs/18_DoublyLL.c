#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* head = NULL;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertAtEnd(int data) {
    Node* temp = head;
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtPosition(int data, int pos) {
    int i;
    Node* newNode = createNode(data);
    Node* temp = head;

    if (pos == 0) {
        insertAtBeginning(data);
        free(newNode);  // Avoid memory leak: node already created inside insertAtBeginning
        return;
    }

    for (i = 0; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next)
        temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteAtBeginning() {
    Node* temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    head = head->next;
    if (head)
        head->prev = NULL;
    free(temp);
}

void deleteAtEnd() {
    Node* temp = head;
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (temp->next == NULL) {
        free(temp);
        head = NULL;
        return;
    }
    while (temp->next)
        temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
}

void deleteAtPosition(int pos) {
    int i;
    Node* temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (pos == 0) {
        deleteAtBeginning();
        return;
    }
    for (i = 0; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }

    if (temp->prev)
        temp->prev->next = temp->next;
    if (temp->next)
        temp->next->prev = temp->prev;

    free(temp);
}

void display() {
    Node* temp = head;
    if (!temp) {
        printf("List is empty!\n");
        return;
    }
    printf("Doubly Linked List: ");
    while (temp) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void swapNodes(int pos1, int pos2) {
    int i, tempData;
    Node* node1 = head;
    Node* node2 = head;

    if (pos1 == pos2)
        return;

    for (i = 0; i < pos1 && node1 != NULL; i++)
        node1 = node1->next;
    for (i = 0; i < pos2 && node2 != NULL; i++)
        node2 = node2->next;

    if (!node1 || !node2) {
        printf("Position(s) out of range\n");
        return;
    }

    // Swap data values
    tempData = node1->data;
    node1->data = node2->data;
    node2->data = tempData;
}

int main() {
    int choice, data, pos, pos1, pos2;

    while (1) {
        printf("\n---Doubly Linked List Operations---\n");
        printf("1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n");
        printf("4. Delete at Beginning\n5. Delete at End\n6. Delete at Position\n");
        printf("7. Display\n8. Swap Nodes\n9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtBeginning(data);
            break;
        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtEnd(data);
            break;
        case 3:
            printf("Enter position and data: ");
            scanf("%d%d", &pos, &data);
            insertAtPosition(data, pos);
            break;
        case 4:
            deleteAtBeginning();
            break;
        case 5:
            deleteAtEnd();
            break;
        case 6:
            printf("Enter position: ");
            scanf("%d", &pos);
            deleteAtPosition(pos);
            break;
        case 7:
            display();
            break;
        case 8:
            printf("Enter two positions to swap: ");
            scanf("%d%d", &pos1, &pos2);
            swapNodes(pos1, pos2);
            break;
        case 9:
            exit(0);
        default:
            printf("Invalid Choice!\n");
        }
    }

    return 0;
}
