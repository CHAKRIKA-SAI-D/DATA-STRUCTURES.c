#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the binary search tree
struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

// Function to create a new node
struct node *create(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;
    return newNode;
}

// Function to insert a new node in the BST
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

// Function to perform inorder traversal of the BST
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

// Function to search for a node with a given value in the BST
struct node* search(struct node* root, int d) {
    if (root == NULL || root->data == d) {
        return root;
    }
    if (root->data < d) {
        return search(root->right, d);
    }
    return search(root->left, d);
}

// Function to find the node with the minimum value in a subtree
struct node* minValueNode(struct node* node) {
    struct node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node with a given value from the BST
struct node* deleteNode(struct node* root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 8);

    printf("Inorder traversal before deletion: ");
    inorder(root);
    printf("\n");

    int keyToDelete = 5;
    root = deleteNode(root, keyToDelete);

    printf("Inorder traversal after deleting %d: ", keyToDelete);
    inorder(root);
    printf("\n");

    return 0;
}
----------------------------------------------------------------------------------------------------------------
  #output:
Inorder traversal before deletion: 2    3       4       5       6       7       8
Inorder traversal after deleting 5: 2   3       4       6       7       8
  
