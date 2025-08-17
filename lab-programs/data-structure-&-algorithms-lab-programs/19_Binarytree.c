#include <stdio.h>
#include <conio.h>  // For getch()

#define MAX 100
int tree[MAX];

// Initialize tree
void initializeTree() {
    int i;
    for (i = 0; i < MAX; i++)
        tree[i] = -1;
}

// Insert root
void insertRoot(int key) {
    tree[0] = key;
}

// Insert left child
void insertLeft(int parent, int key) {
    int i;
    for (i = 0; i < MAX; i++) {
        if (tree[i] == parent) {
            int left = 2 * i + 1;
            if (left < MAX)
                tree[left] = key;
            else
                printf("Left index out of range.\n");
            return;
        }
    }
    printf("Parent not found.\n");
}

// Insert right child
void insertRight(int parent, int key) {
    int i;
    for (i = 0; i < MAX; i++) {
        if (tree[i] == parent) {
            int right = 2 * i + 2;
            if (right < MAX)
                tree[right] = key;
            else
                printf("Right index out of range.\n");
            return;
        }
    }
    printf("Parent not found.\n");
}

// a. Print left and right child of a specified node
void printChildren(int key) {
    int i;
    for (i = 0; i < MAX; i++) {
        if (tree[i] == key) {
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            printf("Left child of %d: %d\n", key, (l < MAX && tree[l] != -1) ? tree[l] : -1);
            printf("Right child of %d: %d\n", key, (r < MAX && tree[r] != -1) ? tree[r] : -1);
            return;
        }
    }
    printf("Node not found.\n");
}

// b. Print ancestors of a node
void printAncestors(int key) {
    int i, index = -1;
    for (i = 0; i < MAX; i++) {
        if (tree[i] == key) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Node not found.\n");
        return;
    }
    printf("Ancestors of %d: ", key);
    while (index != 0) {
        index = (index - 1) / 2;
        printf("%d ", tree[index]);
    }
    printf("\n");
}

// c. Print nodes at a specific level
void printNodesAtLevel(int level) {
    int i;
    int start = (1 << level) - 1;
    int end = (1 << (level + 1)) - 2;

    printf("Nodes at level %d: ", level);
    for (i = start; i <= end && i < MAX; i++) {
        if (tree[i] != -1)
            printf("%d ", tree[i]);
    }
    printf("\n");
}

// d. Print all leaf nodes
void printLeafNodes() {
    int i;
    printf("Leaf nodes: ");
    for (i = 0; i < MAX; i++) {
        if (tree[i] != -1) {
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            if ((l >= MAX || tree[l] == -1) && (r >= MAX || tree[r] == -1)) {
                printf("%d ", tree[i]);
            }
        }
    }
    printf("\n");
}

// Main function for Turbo C
void main() {
    initializeTree();

    // Building a simple binary tree
    insertRoot(1);
    insertLeft(1, 2);
    insertRight(1, 3);
    insertLeft(2, 4);
    insertRight(2, 5);
    insertLeft(3, 6);

    // Operations
    printChildren(2);        // Should print children of node 2
    printAncestors(5);       // Should print ancestors of node 5
    printNodesAtLevel(2);    // Should print nodes at level 2
    printLeafNodes();        // Should print all leaf nodes

    getch();  // Pause output in Turbo C
}
