//INSERTION AND CREATION OF A LINKED LIST

#include <stdlib.h> 
#include <stdio.h>

//creation of a sructure
struct node{
  int data;
  struct node * next;
};
struct node*head,*tail;

//for printing the linked list data
void printlist(struct node *ptr){
    while(ptr!=NULL){
        printf("%5d\t",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

//for the creation of linked list
void create(int data){
    struct node * new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->next=NULL;
    if(head==NULL){
        head=new;
        tail=new;
    }
    else{
        tail->next=new;
        tail=new;
    }
}

//insertion at the beginning
void insertFirst(int data){
    struct node * new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->next=head;
    head=new;
}

//insertion in between the list
void insertbetween(int position,int data,struct node * ptr){
    struct node * new=(struct node*)malloc(sizeof(struct node));
    new->next=NULL;
    new->data=data;
    int i=1;
    while(i!=position-1){
        ptr=ptr->next;
        i++;
    }
    new->next=ptr->next;
    ptr->next=new;
}

//insertion at the end of list
void insertlast(int data){
    struct node * new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->next=NULL;
        if (new==NULL){
            head=NULL;
            tail=NULL;
        }else{
            tail->next=new;
            tail=new;
    }
}

int main()
{
    int n;
    printf("enter the size:");
    scanf("%d",&n);
    //for entering data into linked list
    for(int i=0;i<n;i++){
        int data;
        scanf("%d",&data);
        create(data);
    }
    printlist(head);
    int pos,val;
    printf("enter the position and value:");
    scanf("%d",&pos);
    scanf("%d",&val);
    if (pos==1){       //starting
    insertFirst(val);
    printlist(head);
    }
    else if (pos==n+1){      //last
    insertlast(val);
    printlist(head);
    }
    else{                 //in between
    insertbetween(pos,val,head);
    printlist(head);
    }
    return 0;
}

-------------------------------------------------------------------------------------------------------------------------------------------------------

  #output:

  --test case 1:
enter the size:5
1
2
3
4
5
    1       2       3       4       5
enter the position and value:1
0
    0       1       2       3       4       5

  ------------------------------------------------
--test case 2:
enter the size:5
1
3
4
5
6
    1       3       4       5       6
enter the position and value:2
2
    1       2       3       4       5       6

  ------------------------------------------------
  --test case 3:
enter the size:5
1
2
3
4
5
    1       2       3       4       5
enter the position and value:6
6
    1       2       3       4       5       6
