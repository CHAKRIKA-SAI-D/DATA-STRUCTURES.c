//Quadratic Probing

#include <stdio.h>
#include<stdlib.h>

//Displaying the hash table
void display(int a[],int n){
for(int i=0;i<n;i++){
printf("%d\n",a[i]);
}
}

//logic for Quadratic probing
void quadratic_probing(){
int n;
printf("Enter the number of keys to be inserted?");
scanf("%d",&n);

int m;
printf("Enter the size of hash tabel or (m)?");
scanf("%d",&m);
int a[m];

//Initialising every key in the hash table as zero
for(int i=0;i<m;i++){
a[i]=0;
}
for(int i=0;i<n;i++){
int k;
printf("Enter key:");
scanf("%d",&k);
int h=k%m;
if(a[h]==0){
a[h]=k;
}

//resolution technique
else{
int j=1;
while(a[(h+(j*j))%m]!=0){
h=(h+(j*j))%m;
j++;
}
a[(h+(j*j))%m]=k;
}
}
display(a,m);
return;
}

//function calling
int main(){
quadratic_probing();
return 0;
}

----------------------------------------------------------------------------------------------------------------
  #output:
Enter the number of keys to be inserted?7
Enter the size of hash tabel or (m)?7
Enter key:50
Enter key:700
Enter key:76
Enter key:85
Enter key:92
Enter key:73
Enter key:101
700
50
85
92
73
101
76
