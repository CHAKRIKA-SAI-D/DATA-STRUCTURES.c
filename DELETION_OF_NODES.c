//deleting nodes at different positions
#include <stdlib.h>
#include <stdio.h>

//creation of structure
struct node{
    int data;
    struct node * next;
};
struct node *head,*tail;

//for printing the linked list
void printlist(struct node*ptr){
    while(ptr!=NULL){
        printf("%5d\t",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

//for creation of nodes
void createlist(int data){
    struct node * new=(struct node*)malloc(sizeof(struct node));
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

//for deletion at starting
void deletestart(struct node*ptr){
    head=ptr->next;
}

//for deletion at end
void deleteEnd(struct node*ptr,int n){
    int i=0;
    while(i!=n-2){
        ptr=ptr->next;
        i++;
    }
    ptr->next=NULL;
    tail=ptr;
}

//for deletion in between
void deleteInBetween(int pos,struct node *ptr){
    int i=0;
    while(i!=pos-2){
        ptr=ptr->next;
        i++;
    }
    ptr->next=ptr->next->next;
}

int main()
{
    int n;
    printf("enter the size: ");
    scanf("%d",&n);
    
    //for creating the linked list
    for (int i=0;i<n;i++){
        int temp;
        scanf("%d",&temp);
        createlist(temp);
    }
    printlist(head);
    int pos;
    printf("enter the position to delete the node: ");
    scanf("%d",&pos);
    if (pos==1){                //starting
        deletestart(head);
        printlist(head);
    }else if(pos==n-1){          //ending
       deleteEnd(head,n);
       printlist(head);
    }else{                       //in between
    deleteInBetween(pos,head);
    printlist(head);
    }
    return 0;
}

----------------------------------------------------------------------------------------------------------------------------------------------------
#output:
  --test case 1:
  enter the size: 5
0 
1
2
3
4
    0       1       2       3       4
enter the position to delete the node: 1
    1       2       3       4

  -------------------------------------------
--test case 2:
enter the size: 5
1
2
0
3
4
    1       2       0       3       4
enter the position to delete the node: 3
    1       2       3       4

  ---------------------------------------------
--test case 3:
enter the size: 5
1
2
3
4
5
    1       2       3       4       5
enter the position to delete the node: 5
    1       2       3       4
