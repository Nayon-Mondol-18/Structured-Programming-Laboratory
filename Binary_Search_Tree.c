//****************************************************************
// Title : Linked representation of a binary search tree.
// Author : Nayon Mondol, Undergrduate student, Khulna University.
//****************************************************************
#include <stdio.h>
#include <stdlib.h>

struct Binary_Search_Tree {
    int value;
    struct Binary_Search_Tree *left, *right;
};

typedef struct Binary_Search_Tree node;

void Add_Node(node *root, int n) {
    if (n > root -> value) {
        if (root -> right == NULL) {
            node *temp = (node *)malloc(sizeof(node));
            temp -> value = n, temp -> left = NULL, temp -> right = NULL;
            root -> right = temp;
            return;
        } else
            Add_Node(root -> right, n);
    } else {
        if (root -> left == NULL) {
            node *temp = (node *)malloc(sizeof(node));
            temp -> value = n, temp -> left = NULL, temp -> right = NULL;
            root -> left = temp;
            return;
        } else
            Add_Node(root -> left, n);
    }
}

void inOrderTraversal(node *root) {
    if (root == NULL) return;
    inOrderTraversal(root -> left);
    printf("%d ", root -> value);
    inOrderTraversal(root -> right);
}

int main() {
    node *root = (node *)malloc(sizeof(node));
    printf("Enter the root node : ");
    scanf("%d", &root->value);
    root -> left = NULL, root -> right = NULL;
    int n;
    
    while(1){
        printf("Enter the next node (Enter -1 if there's no node left) : ");
        scanf("%d", &n);
        if(n == -1) break;
        Add_Node(root, n);
    }

    printf("\n");
    inOrderTraversal(root);
    // If the inorder traversal is sorted in ascending order
    // then the tree represents a binary search tree.
}