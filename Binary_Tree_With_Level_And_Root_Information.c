//*******************************************************************************
// Title : Linked representation of a binary tree with root and level information
// Author : Nayon Mondol, Undergrduate student, Khulna University.
//*******************************************************************************

#include <stdio.h>
#include <stdlib.h>

struct binaryTree {
    int data, level;
    struct binaryTree *left, *right, *root;
};

typedef struct binaryTree node;

void preOrderTraversal(node *root) {
    if (root == NULL) return;
    printf("%d ", root -> data);
    preOrderTraversal(root -> left);
    preOrderTraversal(root -> right);
}

void inOrderTraversal(node *root) {
    if (root == NULL) return;
    inOrderTraversal(root -> left);
    printf("%d ", root -> data);
    inOrderTraversal(root -> right);
}

void postOrderTraversal(node *root) {
    if (root == NULL) return;
    postOrderTraversal(root -> left);
    postOrderTraversal(root -> right);
    printf("%d ", root -> data);
}

int main() {
    node *root = (node *)malloc(sizeof(node)), *queue[1000], *p;
    printf("Enter the root node : ");
    scanf("%d", &root->data);
    root -> level = 0, root -> root = NULL;
    int front = 0, rear = 0;
    queue[0] = root, p = root;

    while (front <= rear) {
        printf("Enter the left child of %d (Enter -1 for no left child) : ", p -> data);
        node *tempLeft = (node *)malloc(sizeof(node));
        scanf("%d", &tempLeft->data);
        if (tempLeft -> data == -1)
            tempLeft = NULL;
        else {
            tempLeft -> level = (p -> level) + 1;
            tempLeft -> root = p;
            queue[++rear] = tempLeft;
        }
        p -> left = tempLeft;

        printf("Enter the right child of %d (Enter -1 for no right child) : ", p -> data);
        node *tempRight = (node *)malloc(sizeof(node));
        scanf("%d", &tempRight -> data);
        if (tempRight -> data == -1)
            tempRight = NULL;
        else {
            tempRight -> level = (p -> level) + 1;
            tempRight -> root = p;
            queue[++rear] = tempRight;
        }
        p -> right = tempRight;

        p = queue[++front];
    }
    
    printf("\nThis is the preorder traversal of the generated tree\n");
    preOrderTraversal(root);

    printf("\nThis is the postorder traversal of the generated tree\n");
    postOrderTraversal(root);

    printf("\nThis is the inorder traversal of the generated tree\n");
    inOrderTraversal(root);
}