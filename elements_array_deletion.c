#include <stdio.h>
void main(){
int a[100];
int n;
printf("enter the size:");
scanf("%d",&n);
printf("enter the elemets: ");
for (int i=0;i<n;i++){
scanf("%d",&a[i]);
}
printf("your elements are: "); 
for (int i=0;i<n;i++){
printf("%d",a[i]);
}
int pos;
printf("enter position to delete:");
scanf("%d",&pos);
for(int i=pos-1;i<n-1;i++){
a[i]=a[i+1];
}
for (int i=0;i<n-1;i++){
printf("%5d",a[i]);
}
return;
}


#output:
enter the size:5
enter the elemets: 1
2
3
4
5
your elements are: 12345
enter position to delete:3
    1    2    4    5
