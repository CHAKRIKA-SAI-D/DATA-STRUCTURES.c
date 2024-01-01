#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node*left;
    struct node*right;
    int height;
};
struct node*root;

struct node*create(int data){
    struct node*new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->left=NULL;
    new->right=NULL;
    new->height=1;
    return new;
}
int max(int a,int b){
    if (a>b){
        return a;
    }return b;
}

int getheight(struct node*temp){
    if(temp==NULL){
        return 0;
    }
    return temp->height;
}

int getbalancefactor(struct node*n){
    if(n==NULL){
        return 0;
    }return getheight(n->left)-getheight(n->right);
}

struct node*rightrotate(struct node*y){
    struct node*x=y->left;
    // struct node*t1=x->left;
    struct node*t2=x->right;
    // struct node*t3=y->right;
    // x->left=t1;
    x->right=y;
    y->left=t2;
    // y->right=t3;
    y->height=max(getheight(y->right),getheight(y->left))+1;
    x->height=max(getheight(x->right),getheight(x->left))+1;
    return x;
}


struct node*leftrotate(struct node *x){
    struct node*y=x->right;
    // struct node*t1=x->left;
    struct node*t2=y->left;
    // struct node*t3=y->right;
    y->left=x;
    // y->right=t3;
    // x->left=t1;
    x->right=t2;
    y->height=max(getheight(y->right),getheight(y->left))+1;
    x->height=max(getheight(x->right),getheight(x->left))+1;
    return y;    
}

struct node*insert(struct node*node,int key){
    if (node==NULL){
        return create(key);
    }
    if(key<node->data){
        node->left=insert(node->left,key);
    }else if(key>node->data){
    node->right=insert(node->right,key);
}
    node->height=1+max(getheight(node->left),getheight(node->right));
    int bf=getbalancefactor(node);
    //left left ->single right
    if(bf>1 && key<node->left->data){
        return rightrotate(node);
    }
    //right right->single left
    if(bf<-1 && key>node->right->data){
        return leftrotate(node);
    }
    //left right-> left(child) right(parent)
    if(bf>1 && key>node->left->data){
        node->left=leftrotate(node->left);
        return rightrotate(node);
    }
    // right left-> right(child) left(parent)
    if(bf<-1 && key<node->right->data){
        node->right=rightrotate(node->right);
         return leftrotate(node);
    }
    return node;
}

void inorder(struct node*n){
    if(n!=NULL){
    inorder(n->left);
     printf("%d\t",n->data);
    inorder(n->right);
    }
}

void preorder(struct node*n){
    if(n!=NULL){
    printf("%d\t",n->data);
    preorder(n->left);
    preorder(n->right);
    }
}
int main()
{
   struct node*root=NULL;
//   root=insert(root,45);
   root=insert(root,1);
   root=insert(root,2);
//   root=insert(root,3);
   root=insert(root,4);
   root=insert(root,5);
   root=insert(root,6);
   root=insert(root,3);
   inorder(root);
//   root=insert(root,45);
   printf("\n");
   preorder(root);

    return 0;
}


---------------------------------------------------------------------------------------------------------------------------------
  #output:
  1       2       3       4       5       6
  4       2       1       3       5       6
