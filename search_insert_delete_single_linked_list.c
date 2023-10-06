// creation insertion deletion and searching in single linked list

#include <stdio.h>
#include <stdlib.h>

//cretion of structure
struct node{
int data;
struct node*next;
};
struct node *head;
struct node *tail;

//searching of element in linked list
int searchEle(int data){
    struct node*new=head;
    int count;
    while(new!=NULL){
        count++;
        if (data==new->data){
            return count+1;
            break;
        }else{
         new=new->next;   
        }
    }
    return -1;
}

//condition for insertion at last and creation
void create_link(int data){
struct node*new=(struct node*)malloc(sizeof(struct node*));
new->data=data;
new->next=NULL;
if (head==NULL){
head=new;
tail=new;
}
else{
tail->next=new;
tail=new;
}
return;
}

//condition for insertion first
void insert_first(struct node *ptr,int data){
struct node*new=(struct node*)malloc(sizeof(struct node*));
new->data=data;
new->next=head;
head=new;
}

//condition for deletion (first)
void deletion_first(){
head=head->next;
}

//condition for deletion (last)
void deletion_last(int n){
struct node*ptr=head;
int i=0;
while(i!=n-2){
ptr=ptr->next;
i++;
}
ptr->next=NULL;
}

//condition for deletion (in between)
void deletion_between(int pos){
struct node*ptr=head;
int i=0;
while(i!=pos-2){
ptr=ptr->next;
i++;
}
ptr->next=ptr->next->next;
}

// condition for insertion (in between)
void insert_between(int data,int pos){
struct node*new=(struct node*)malloc(sizeof(struct node*));
new->data=data;
new->next=NULL;
struct node *temp=head;
int count=0;
while(count!=pos-2){
temp=temp->next;
count++;
}
new->next=temp->next;
temp->next=new;
}

//for printing the linked list
void print_list(struct node*ptr){
while(ptr!=NULL){
printf("%5d\t",ptr->data);
ptr=ptr->next;
}
}

int main(){
int n;
printf("enter the size:");
scanf("%d",&n);
for(int i=0;i<n;i++){
int data;
scanf("%d",&data);
create_link(data);
}
print_list(head);


//for insertion of elements of linked list
int pos;
int data;
printf("enter the data:");
scanf("%d",&data);
printf("enter the position:");
scanf("%d",&pos);
if (pos==1){           // first position to insert an element to linked list
insert_first(head,data);
print_list(head);
printf("\n");
}else if(pos==n+1){  //last insertion
create_link(data);
print_list(head);
printf("\n");
}
else{              //in between insertion
insert_between(data,pos);
print_list(head);
printf("\n");
}


//for deletion of data in linked list
printf("enter the position to delete: ");
int del;
scanf("%d",&del);
if (del==1){          //if the element is is first position
deletion_first();
print_list(head);
printf("\n");
}else if (del==n){   //if the element is last in linked list
deletion_last(n);
print_list(head);
printf("\n");
}else{              //if the node is inbetween the linked list
deletion_between(del);
print_list(head);
}

printf("enter the element for searching: ");
int search;   // searching element in linked list
scanf("%d",&search);
int x=searchEle(search);
if (x==-1){
    printf(" PRESENT NOWHERE ");
}else{
    printf("present at %d",x);
}
return 0;
}

----------------------------------------------------------------------------------------------------------------------------------------------------------------
#output:
  --Test case 1:
enter the size:5
1
2
3
4
0
    1       2       3       4       0   enter the data:0
enter the position:1
    0       1       2       3       4       0
enter the position to delete: 6
    0       1       2       3       4   enter the element for searching: 0
present at 1

----------------------------------------------------------------------------------------
  --Test case 2:
enter the size:5
1
2
3
4
5
    1       2       3       4       5   enter the data:0
enter the position:3
    1       2       0       3       4       5
enter the position to delete: 3
    1       2       3       4       5   enter the element for searching: 0
 PRESENT NOWHERE
