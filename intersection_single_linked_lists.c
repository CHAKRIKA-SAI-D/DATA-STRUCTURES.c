#include <stdlib.h>
#include <stdio.h>

struct node{
    int data;
    struct node* next;
};
struct node* h1, *t1,*h2,*t2;

void create1(int data){
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    if(h1==NULL){
        h1=temp;
        t1=temp;
    }else{
        t1->next=temp;
        t1=temp;
    }
}

void create2(int data){
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    if(h2==NULL){
        h2=temp;
        t2=temp;
    }else{
        t2->next=temp;
        t2=temp;
    }
}

void display(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d\n",a[i]);
    }
}

void same(){
    struct node *temp=h1;
    struct node *temp2=h2;
    int a[10];
    int i=0;
    while(temp!=NULL){
        struct node *temp2=h2;
        while(temp2!=NULL){
            if(temp->data==temp2->data){
                a[i]=temp->data;
                i++;
            }temp2=temp2->next;
        }
        temp=temp->next;
    }
    display(a,i);
}
int main()
{
    create1(10);
    create1(20);
    create1(30);
    create1(90);
    create2(10);
    create2(40);
    create2(20);
    create2(50);
    create2(60);
    same();
    return 0;
}

------------------------------------------------------------------------------------
  #output:
  10
  20
