//queue operations using arrays
#include <stdio.h>
#define size 5
int queue[size];
int f=-1; //front end
int r=-1; //rear end

//inserting elements
void enque(int item){
    if (r==size-1){
        printf("queue overflow!");
        return;
    }else if(f==-1){
       f++;
    }
    r++;
    queue[r]=item;
}

//deleting elements
void deque(){
    if(f==-1||f>r){
        printf("queue underflow!");
        return;
    }else{
        printf("element deleted is %d\n",queue[f]);
        f++;
    }
}

void display(){
    if(f>r){
        printf("queue is empty");
    }else{
    for(int i=f;i<=r;i++){
        printf("%d\n",queue[i]);
        
    }
}
}

void main(){
    enque(10);
    enque(20);
    display();
    deque();
    display();
}

-------------------------------------------------------------------------------------------------------------------------------------
  #output:
  10
  20
  element deleted is 10
  20
