#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;

struct node *create(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;
    return newNode;
}

struct node *insert(struct node *currentNode, int data) {
    if (currentNode == NULL) {
        return create(data);
    } else {
        if (data < currentNode->data) {
            currentNode->left = insert(currentNode->left, data);
        } else {
            currentNode->right = insert(currentNode->right, data);
        }
    }
    return currentNode;
}

void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

int main() {
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 7);

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    printf("Postorder: ");
    postorder(root);
    printf("\n");

    printf("Inorder: ");
    inorder(root);
    printf("\n");

    return 0;
}

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#output:
Preorder: 1     2       3       4       5       6       7
Postorder: 7    6       5       4       3       2       1
Inorder: 1      2       3       4       5       6       7
