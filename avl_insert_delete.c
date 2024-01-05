#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node*left;
    struct node*right;
    int height;
};

struct node*create(int data){
    struct node*new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->left=NULL;
    new->right=NULL;
    new->height=1;
    return new;
}

int max(int a, int b){
    if (a > b){
        return a;
    }
    return b;
}

int getheight(struct node*temp){
    if(temp == NULL){
        return 0;
    }
    return temp->height;
}

int getbalancefactor(struct node*n){
    if(n == NULL){
        return 0;
    }
    return getheight(n->left) - getheight(n->right);
}

struct node*rightrotate(struct node*y){
    struct node*x=y->left;
    struct node*t2=x->right;
    x->right=y;
    y->left=t2;
    y->height=max(getheight(y->right),getheight(y->left))+1;
    x->height=max(getheight(x->right),getheight(x->left))+1;
    return x;
}

struct node*leftrotate(struct node *x){
    struct node*y=x->right;
    struct node*t2=y->left;
    y->left=x;
    x->right=t2;
    y->height=max(getheight(y->right),getheight(y->left))+1;
    x->height=max(getheight(x->right),getheight(x->left))+1;
    return y;    
}

struct node*insert(struct node*node, int key){
    if (node == NULL){
        return create(key);
    }
    if(key < node->data){
        node->left = insert(node->left, key);
    } else if(key > node->data){
        node->right = insert(node->right, key);
    }
    node->height = 1 + max(getheight(node->left), getheight(node->right));
    int bf = getbalancefactor(node);
    
    // Adjustments after insertion (similar to your previous logic)
    // ...

    return node;
}

struct node *search(struct node*root, int data){
     if(root == NULL){
         return root;
     }
     if(root->data == data){
         return root;
     } else if(root->data < data){
         return search(root->right, data);
     } else {
              return search(root->left, data);
     }
 }


struct node* inorder_predecessor(struct node*root){
    if(root->left == NULL){
        return root;
    }
    return inorder_predecessor(root->left);
}

struct node* delete(struct node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = delete(root->left, key);
    } else if (key > root->data) {
        root->right = delete(root->right, key);
    } else {
        if (root->left == NULL || root->right == NULL) {
            struct node* temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }

            free(temp);
        } else {
            struct node* replace = inorder_predecessor(root->right);
            root->data = replace->data;
            root->right = delete(root->right, replace->data);
        }
    }

    if (root == NULL) {
        return root;
    }

    root->height = 1 + max(getheight(root->left), getheight(root->right));

    int bf = getbalancefactor(root);

    // Balance factor check and rotations (similar to your insert function logic)
    // ...

    return root;
}

void inorder(struct node*n){
    if(n != NULL){
        inorder(n->left);
        printf("%d\t",n->data);
        inorder(n->right);
    }
}

void preorder(struct node*n){
    if(n != NULL){
        printf("%d\t",n->data);
        preorder(n->left);
        preorder(n->right);
    }
}

int main() {
    struct node* root = NULL;
     int i=0;
     int ch,d,key,value;
     while(i!=1){
     printf("Enter your choice : ");
     printf("1:Insert\n2:Delete\n3:Search\n4:Inorder\n5:Preorder\n6:Exit");
     scanf("%d",&ch);
     switch(ch){
     case 1:
	     
	     printf("Enter data:");
	     scanf("%d",&d);
	     root=insert(root,d);
	     break;
     case 2:
	     
	     printf("Enter data to be deleted:");
	     scanf("%d",&key);
	     root=delete(root,key);
	     break;
     case 3:
	     
	     printf("Enter the value to be searched:");
	     scanf("%d",&value);
	     root=search(root,value);
	     if(root==NULL){
	     printf("Element not found");
	     }else{
	     printf("Element found");
	     }
	     break;
     case 4:
     	inorder(root);
     	break;
     case 5:
     	preorder(root);
     	break;
     case 6 :
     	i=1;
     	break;
     }
     }
  return 0;
}


-----------------------------------------------------------------------------------------------------------------------------
  #output:
  Enter your choice : 1:Insert
2:Delete
3:Search
4:Inorder
5:Preorder
6:Exit1
Enter data:3
Enter your choice : 1:Insert
2:Delete
3:Search
4:Inorder
5:Preorder
6:Exit1
Enter data:2
Enter your choice : 1:Insert
2:Delete
3:Search
4:Inorder
5:Preorder
6:Exit1
Enter data:1
Enter your choice : 1:Insert
2:Delete
3:Search
4:Inorder
5:Preorder
6:Exit4
1	2	3	Enter your choice : 1:Insert
2:Delete
3:Search
4:Inorder
5:Preorder
6:Exit5
3	2	1	Enter your choice : 1:Insert
2:Delete
3:Search
4:Inorder
5:Preorder
6:Exit2
Enter data to be deleted:2
Enter your choice : 1:Insert
2:Delete
3:Search
4:Inorder
5:Preorder
6:Exit4
1	3	Enter your choice : 1:Insert
2:Delete
3:Search
4:Inorder
5:Preorder
6:Exit3
Enter the value to be searched:2
Element not foundEnter your choice : 1:Insert
2:Delete
3:Search
4:Inorder
5:Preorder
6:Exit3
Enter the value to be searched:3
Element not foundEnter your choice : 1:Insert
2:Delete
3:Search
4:Inorder
5:Preorder
6:Exit6
