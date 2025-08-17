#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a new node
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// a. Print left and right child of a specified node
void printChildren(struct Node *root, int key)
{
    if (root == NULL)
        return;
    if (root->data == key)
    {
        if (root->left)
            printf("Left child of %d: %d\n", key, root->left->data);
        else
            printf("Left child of %d: NULL\n", key);
        if (root->right)
            printf("Right child of %d: %d\n", key, root->right->data);
        else
            printf("Right child of %d: NULL\n", key);
        return;
    }
    printChildren(root->left, key);
    printChildren(root->right, key);
}

// b. Print ancestors of a specified node
int printAncestors(struct Node *root, int key)
{
    if (root == NULL)
        return 0;
    if (root->data == key)
        return 1;
    if (printAncestors(root->left, key) || printAncestors(root->right, key))
    {
        printf("%d ", root->data);
        return 1;
    }
    return 0;
}

// b. Print nodes at specific level
void printLevel(struct Node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else
    {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

// b. Print leaf nodes
void printLeafNodes(struct Node *root)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        printf("%d ", root->data);
    }
    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

void main()
{
    int target, ancestorNode, level;
    
    target = 2;
    ancestorNode = 5;
    level = 3;

    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);

    printf("a. Children of node %d:\n", target);
    printChildren(root, target);

    printf("\n\nb. Ancestors of node %d:\n", ancestorNode);
    printAncestors(root, ancestorNode);

    printf("\n\nNodes at level %d:\n", level);
    printLevel(root, level);

    printf("\n\nLeaf nodes:\n");
    printLeafNodes(root);

    getch();
}
