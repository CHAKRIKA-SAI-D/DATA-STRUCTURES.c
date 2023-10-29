//queue using dynamic memory allocation
#include <stdlib.h>
#include<stdio.h>

//strcture for queue 
struct queue{
    int data;
    struct queue *next;
};
struct queue * front=NULL;//exiting end
struct queue * rear=NULL;//entering end

//inserting elements to queue
void enque(int data){
    struct queue* current=(struct queue*)malloc(sizeof(struct queue));
    current->data=data;
    current->next=NULL;
    if(front==rear&&rear==NULL){
        rear=current;
        front=current;
    }else{
        rear->next=current;
        rear=current;
    }
}

//deleting elements in queue
void deque(){
    if(front==NULL){
        printf("QUEUE UNDERFLOW");
        return;
    }else{
        printf("deleted element is %d",front->data);
        front=front->next;
    }
}

//function to display elements in queue 
void display(){
    if(front==NULL){
        printf("QUEUE IS EMPTY");
        return;
    }else{
        struct queue*temp=front;
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
}

int main(){
    int choice;
    int i=0;
    while(i!=1){
        printf("\nenter the choice:\n 1-Enqueue \n 2-Dequeue \n 3-Display \n 4-Exit \n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                int data;
                printf("enter the data: ");
                scanf("%d",&data);
                enque(data);
                break;            
            case 2:
                deque();
                break;
            case 3:
                display();
                break;
            case 4:
                i=1;
                break;
            default:
                printf("incorrect choice");
                break;
        }
    }return 0;
}
-------------------------------------------------------------------------------------------------------------------------------------------------------
  #output:
  enter the choice:
 1-Enqueue 
 2-Dequeue 
 3-Display 
 4-Exit 
1
enter the data: 10

enter the choice:
 1-Enqueue 
 2-Dequeue 
 3-Display 
 4-Exit 
1
enter the data: 20

enter the choice:
 1-Enqueue 
 2-Dequeue 
 3-Display 
 4-Exit 
1
enter the data: 30

enter the choice:
 1-Enqueue 
 2-Dequeue 
 3-Display 
 4-Exit 
2
deleted element is 10
enter the choice:
 1-Enqueue 
 2-Dequeue 
 3-Display 
 4-Exit 
3
20      30
enter the choice:
 1-Enqueue 
 2-Dequeue 
 3-Display 
 4-Exit 
2
deleted element is 20
enter the choice:
 1-Enqueue 
 2-Dequeue 
 3-Display 
 4-Exit 
3
30
enter the choice:
 1-Enqueue 
 2-Dequeue 
 3-Display 
 4-Exit 
2
deleted element is 30
enter the choice:
 1-Enqueue 
 2-Dequeue 
 3-Display 
 4-Exit 
3
QUEUE IS EMPTY
enter the choice:
 1-Enqueue 
 2-Dequeue 
 3-Display 
 4-Exit 
2
QUEUE UNDERFLOW
enter the choice:
 1-Enqueue 
 2-Dequeue 
 3-Display 
 4-Exit 
4
