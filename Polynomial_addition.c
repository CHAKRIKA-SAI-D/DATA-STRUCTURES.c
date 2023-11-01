//Polynomial addition
#include <stdio.h>
#include<stdlib.h>

//1st polynomial
struct poly1{
    int power;
    int value;
    struct poly1 *next;
};struct poly1 *head1 ,*tail1;

//2nd polynomial
struct poly2{
    int power;
    int value;
    struct poly2*next;
};struct poly2 *head2,*tail2;

//result after adding
struct result{
    int power;
    int value;
    struct result *next;
};struct result *head,*tail;

//creation of 1st polynomial's single linked lists
void create1(int power,int value){
    struct poly1*new=(struct poly1*)malloc(sizeof(struct poly1));
    new->power=power;
    new->value=value;
    new->next=NULL;
    if (head1==NULL){
        head1=new;
        tail1=new;
    }else{
        tail1->next=new;
        tail1=new;
    }
}

//creation of 2nd polynomial's single linked lists
void create2(int power,int value){
    struct poly2*new=(struct poly2*)malloc(sizeof(struct poly2));
    new->power=power;
    new->value=value;
    new->next=NULL;
    if (head2==NULL){
        head2=new;
        tail2=new;
    }else{
        tail2->next=new;
        tail2=new;
    }
}

//inserting elements into result
void insert(int power,int value){
    struct result*new=(struct result*)malloc(sizeof(struct result));
    new->power=power;
    new->value=value;
    new->next=NULL;
    if (head==NULL){
        head=new;
        tail=new;
    }else{
        tail->next=new;
        tail=new;
    }
}

//display function to display the result
void display(){
    struct result*temp=head;
    while(temp!=NULL){
        printf("%dx%d\t",temp->value,temp->power);
        temp=temp->next;
    }
}

//It performs addition between 2 polynomials
void add(){
    struct poly1*temp1 = head1;
    struct poly2*temp2=head2;
    while(temp1!=NULL){
        if(temp1 ==NULL||temp2 ==NULL){
            break;
        }
        else if(temp1->power==temp2->power){
            insert(temp1->power,temp1->value+temp2->value);
            temp1=temp1->next;
            temp2=temp2->next;
        }else{
            int rpow=(temp1->power>temp2->power)?temp1->power:temp2->power;
            if (rpow==temp1->power){
                insert(temp1->power,temp1->value);
                temp1=temp1->next;
            }else{
                insert(temp2->power,temp2->value);
                temp2=temp2->next;
            }
        }
    }if(temp1!=NULL||temp2!=NULL){
        if (temp1==NULL){
            while(temp2!=NULL){
                insert(temp2->power,temp2->value);
                temp2=temp2->next;
            }
        }else{
            while(temp1!=NULL){
                insert(temp1->power,temp1->value);
                temp1=temp1->next;
            }
        }
    }
}

int main(){
    create1(3,1);
    create1(2,1);
    create1(0,1);
    create2(3,1);
    create2(2,1);
    create2(1,1);
    create2(0,1);
    add();
    display();
    
}
-------------------------------------------------------------------------------------------------------------------------------------------
#output:
  2x3     2x2     1x1     2x0
