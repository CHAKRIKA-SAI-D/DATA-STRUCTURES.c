#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};struct node *head;
struct node *tail;

void create(int data){
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->next=NULL;
    if(head==NULL){
        head=new;
        tail=new;
    }else{
        tail->next=new;
        tail=new;
    }
}

//reversing a linked list
void reverse(){
    struct node*current=head;
    struct node * prev=NULL;
    struct node * next;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }head=prev;
}
void display(){
    struct node*ptr=head;
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
}

int main(){
    create(10);
    create(12);
    create(13);
    create(99);
    display();
    reverse();
    printf("\n");
    display();
    return 0;
}
--------------------------------------------------------------------------------------------------------------------------------------------------------------
  #output:
 10      12      13      99
 99      13      12      10 
