//implementing stacks using queue
#include<stdio.h>
#include<stdlib.h>
//queue template
struct queue{
int data;
struct queue*next;
};
struct queue *r1=NULL;
struct queue *r2=NULL; 
struct queue *f1=NULL;
struct queue *f2=NULL;

//for creation of initial queue
void create1(int data){
struct queue*new=(struct queue*)malloc(sizeof(struct queue));
new->data=data;
new->next=NULL;
if (r1==NULL && f1==NULL){
r1=new;
f1=new;
}else{
r1->next=new;
r1=new;
}
}

//resultant queue
void rev(int data){
struct queue*new=(struct queue*)malloc(sizeof(struct queue));
new->data=data;
new->next=NULL;
if (r2==NULL && f2==NULL){
r2=new;
f2=new;
}else{
r2->next=new;
r2=new;
}
}

//popping from rear and enqueing elemens to another queue
void operations(){
struct queue *temp=f1;
do{
struct queue *temp=f1;
while(temp->next!=r1){
temp=temp->next;
}rev(temp->next->data);
r1=temp;
}while(r1!=f1);
rev(temp->data);
}

//displays as stacks
void display(){
struct queue *temp=f2;
while(temp!=NULL){
printf("%d\t",temp->data);
temp=temp->next;
}
}

int main(){
create1(1);
create1(2);
create1(3);
create1(4);
operations();
display();
}

------------------------------------------------------------------------------------------------------
  #output:
  4	3	2	1	
