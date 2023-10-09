//cretion,searching,insertion and deletion in  double linked list
#include <stdio.h>
#include <stdlib.h>

//creation of a structure
struct dubnode {
    struct dubnode* prev;
    int data;
    struct dubnode* next;
};

struct dubnode* head = NULL;
struct dubnode* tail = NULL;

//creation of a linked list
void create(int data) {
    struct dubnode* new_node = (struct dubnode*)malloc(sizeof(struct dubnode));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
}

//printing a linked list
void print() {
    struct dubnode* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

//insertion at begin
void insertion_begin(int data){
    struct dubnode* new= (struct dubnode*)malloc(sizeof(struct dubnode));
    new->data=data;
    new->prev=NULL;
    new->next=head;
    head->prev=new;
    head=new;
}

//insertion at last
void insertion_last(int data){
    struct dubnode* new= (struct dubnode*)malloc(sizeof(struct dubnode));
    new->next=NULL;
    new->prev=NULL;
    new->data=data;
    struct dubnode*ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    new->prev=ptr;
    ptr->next=new;
    tail=new;
}

//insertion of element at position
void insertion_pos(int data,int pos){
    struct dubnode* new= (struct dubnode*)malloc(sizeof(struct dubnode));
    new->next=NULL;
    new->prev=NULL;
    int i=1;
    struct dubnode*ptr=head;
    while(i!=pos-1){
        ptr=ptr->next;
        i++;
    }
    new->next=ptr->next;
    ptr->next->prev=new;
    new->prev=ptr;
    ptr->next=new;
}

//deletion of element at beginning
void delete_begin(){
    head=head->next;
    head->prev->next=NULL;
    head->prev=NULL;
}

//deletion ofelement at last
void delete_last(){
    struct dubnode*ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr=ptr->prev;
    ptr->next->prev=NULL;
    ptr->next=NULL;
}

//deletion of element position 
void delete_pos(int pos){
    int i=0;
    struct dubnode*ptr=head;
    while(i!=pos-2){
        ptr=ptr->next;
        i++;
    }ptr->next->next->prev=ptr;
    ptr->next=ptr->next->next;
}

//searching an element
void search(int data1){
    struct dubnode*ptr=head;
    int pos=1;
    while(ptr!=NULL){
        if(ptr->data==data1){
            printf("Present at %d",pos);
            return;
        }else{
            ptr=ptr->next;
            pos++;
        }
    }printf("Present NoWhere!");
    return;
}

int main(){
    int n;                     //size of linked list
    printf("enter the number of elements in list: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){             //creating linked list
        int data;
        printf("enter : ");
        scanf("%d",&data);
        create(data);
    }
    print();
    int pos1;
    printf("enter the position to insert :");
    scanf("%d",&pos1);
    int data3;
    printf("enter the data: ");
    scanf("%d",&data3);
    if(pos1==1){
    insertion_begin(data3);     // insertion at the beginning
    print();
    }else if(pos1==n+1){        //insertion at the last  
    insertion_last(data3);
    print();
    }
    else{                      //insertion at some position
    insertion_pos(data3,pos1);
    print();
    }
    int pos2;
    printf("enter the position to delete : ");
    scanf("%d",&pos2);
    if (pos2==1){
    delete_begin();            //deletion at begining
    print();
    }else if(pos2==n+1){
    delete_last();            //deletion at last
    print();
    }else{ 
    delete_pos(pos2);       //deletion at some position
    print();
    }
    int data2;
    printf("enter the data to be search:");
    scanf("%d",&data2);
    search(data2);          //searching the element
    return 0;
}

-------------------------------------------------------------------------------------------------------------------------------------------------------
  #output:
  testcase1:
enter the number of elements in list: 3
enter : 1
enter : 2
enter : 3
1 2 3 
enter the position to insert :1
enter the data: 0
0 1 2 3 
enter the position to delete : 1
1 2 3 
enter the data to be search:3
Present at 3
----------------------------------------------------------
  test case 2:
enter the number of elements in list: 3
enter : 1
enter : 2
enter : 3
1 2 3 
enter the position to insert :4
enter the data: 0
1 2 3 0 
enter the position to delete : 4
1 2 3 
enter the data to be search:4
Present NoWhere!

  ----------------------------------------------------------
  test case 3:
enter the number of elements in list: 3
enter : 1
enter : 2
enter : 3
1 2 3 
enter the position to insert :2
enter the data: 0
1 0 2 3 
enter the position to delete : 2
1 2 3 
enter the data to be search:2
Present at 2
