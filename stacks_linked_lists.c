//stacks using linked lists

#include <stdio.h>
#include <stdlib.h>
struct stack{
    int data;
    struct stack *next;
};
struct stack *top;

//push operation in stacks
void push(int data){
    struct stack *new=(struct stack *)malloc(sizeof(struct stack));
    new->data=data;
    new->next=NULL;
    if (top==NULL){
        top=new;
    }else{
        new->next=top;
        top=new;
    }
}

//pop operation in stacks
void pop(){
    if (top==NULL){
        printf(" STACK UNDER FLOW");
    }else{
        printf("popped element is : %d",top->data);
        struct stack *temp;
        temp=top->next;
        top->next=NULL;
        top=temp;
    }
}

//to display elements in stacks
void display(){
    struct stack *temp=top;
    while(temp!=NULL){
        printf("%5d\t",temp->data);
        temp=temp->next;
    }
}

//pushing poping and displaying process starts here

void main(){
    int i=1;
    while(i!=0){
    int choice;
    printf("\n1:push\n2:pop\n3:Display\n4:Exit\n Enter choice ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            int data;
            printf("enter the item : ");
            scanf("%d",&data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3: display();
        break;
        case 4:
        i=0;
        break;
        default:
        printf("enter correct value: ");
    }   
    }
}
------------------------------------------------------------------------------------------------------------------------------------------------
  #output:
  1:push
2:pop
3:Display
4:Exit
 Enter choice 1
enter the item : 12

1:push
2:pop
3:Display
4:Exit
 Enter choice 1
enter the item : 13

1:push
2:pop
3:Display
4:Exit
 Enter choice 1
enter the item : 16

1:push
2:pop
3:Display
4:Exit
 Enter choice 2
popped element is : 16
1:push
2:pop
3:Display
4:Exit
 Enter choice 3
   13      12
1:push
2:pop
3:Display
4:Exit
 Enter choice 4
