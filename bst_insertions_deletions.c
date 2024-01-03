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
    int ch=1;
    while(ch!=0){
    printf("enter the choice: ");
    int x;
    printf("1:insert\n2:delete\n3:display\n4:search\n5:exit");
    scanf("%d",&x);
    switch(x){
        case 1: 
            int q;
            printf("enter the data");
            scanf("%d",&q);
            root=insert(root,q);
            break;
        case 2:
            int d;
            printf("enter the key to delete : ");
            scanf("%d",&d);
            root=deleteNode(root,d);
            break;
        case 3:
            inorder(root);
            break;
        case 4:
            int p;
            printf("enter the key to search: ");
            scanf("%d", &p);
            struct node* result = search(root, p);
            if (result != NULL) {
                printf("Key %d found in the BST\n", p);
            } else {
                printf("Key %d not found in the BST\n", p);
            }
            break;
        case 5:
            ch=0;
            break;
    }
    }
    return 0;
}
----------------------------------------------------------------------------------------------------------------
  #output:
enter the choice: 1:insert
2:delete
3:display
4:search
5:exit1
enter the data2
enter the choice: 1:insert
2:delete
3:display
4:search
5:exit1
enter the data3
enter the choice: 1:insert
2:delete
3:display
4:search
5:exit3
2       3       enter the choice: 1:insert
2:delete
3:display
4:search
5:exit4
enter the key to search: 3
Key 3 found in the BST
enter the choice: 1:insert
2:delete
3:display
4:search
5:exit4
enter the key to search: 1
Key 1 not found in the BST
enter the choice: 1:insert
2:delete
3:display
4:search
5:exit2
enter the key to delete : 2
enter the choice: 1:insert
2:delete
3:display
4:search
5:exit3
3       enter the choice: 1:insert
2:delete
3:display
4:search
5:exit4
enter the key to search: 2
Key 2 not found in the BST
enter the choice: 1:insert
2:delete
3:display
4:search
5:exit5
  
