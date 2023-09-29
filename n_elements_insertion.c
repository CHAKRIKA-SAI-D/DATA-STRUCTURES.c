#include <stdio.h>
void main(){
int a[100];
int n;
printf("enter the size of array:");
scanf("%d",&n);
for (int i=0;i<n;i++){	
scanf("%d",&a[i]);
}
int x;
printf("enter the no of elements to be inserted: ");
scanf("%d",&x);
int i=0;
int j=0;
for (i=0;i<x;i++){
int ele;
int pos;
printf("enter the position: ");
scanf("%d",&pos);
printf("enter the element: ");
scanf("%d",&ele);
for (j=n;j>pos-1;j--){
a[j]=a[j-1];
}
a[pos-1]=ele;
n+=1;
}
for(int i=0;i<n;i++){
printf("%5d",a[i]);
}
return;
}


#output:
enter the size of array:3
1
2
3
enter the no of elements to be inserted: 2
enter the position: 1
enter the element: 0
enter the position: 4
enter the element: 0
    0    1    2    0    3
