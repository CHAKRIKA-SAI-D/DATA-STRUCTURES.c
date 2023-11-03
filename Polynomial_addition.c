//Polynomial addition
#include <stdio.h>
#include <stdlib.h>
//polynomial
struct poly{
    int power;
    int value;
    struct poly *next;
};struct poly *head1 ,*tail1,*head2,*tail2,*head,*tail;

//creation of 1st polynomial's single linked lists
void create1(int power,int value){
    struct poly*new=(struct poly*)malloc(sizeof(struct poly));
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
    struct poly*new=(struct poly*)malloc(sizeof(struct poly));
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
    struct poly*new=(struct poly*)malloc(sizeof(struct poly));
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
    struct poly*temp=head;
    while(temp!=NULL){
        printf("%dx^%d\t",temp->value,temp->power);
        temp=temp->next;
    }
}

//It performs addition between 2 polynomials
void add(){
    struct poly*temp1 = head1;
    struct poly*temp2=head2;
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
    int deg;
    printf("enter the degree of first polynomial:");
    scanf("%d",&deg);
    while(deg!=-1){
    int value;
    printf("enter value for power %d: ",deg);
    scanf("%d",&value);
    create1(deg,value);
    deg--;
    }
    int deg1;
    printf("enter the degree of second polynomial:");
    scanf("%d",&deg1);
    while(deg1!=-1){
    int value1;
    printf("enter value for power %d: ",deg1);
    scanf("%d",&value1);
    create2(deg1,value1);
    deg1--;
    }
    add();
    display();
}
-------------------------------------------------------------------------------------------------------------------------------------------
#output:
enter the degree of first polynomial:4
enter value for power 4: 12
enter value for power 3: 0
enter value for power 2: 11
enter value for power 1: 4
enter value for power 0: 9
enter the degree of second polynomial:5
enter value for power 5: 2
enter value for power 4: 0
enter value for power 3: 0
enter value for power 2: 0
enter value for power 1: 5
enter value for power 0: 10
2x^5	12x^4	0x^3	11x^2	9x^1	19x^0
  
