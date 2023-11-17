//Collision resolution technique
//Linear Probing

#include <stdio.h>
#include<stdlib.h>

//to display the hash table
void display(int a[],int n){
for(int i=0;i<n;i++){
printf("%d\n",a[i]);
}
}

//linear probing logics
void linear_probing(){
int n;
printf("Enter the number of keys to be inserted?");
scanf("%d",&n);
int m;
printf("Enter the size of hash tabel or (m)?");
scanf("%d",&m);
int a[m];
// place the zeroes in hash table
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
else{
int j=1;
while(a[(h+j)%m]!=0){
j++;
}
a[(h+j)%m]=k;
}
}
//displaying the hash table
display(a,m);
return;
}


//function calling
int main(){
linear_probing();
return 0;
}

---------------------------------------------------------------------------------------------------------------------------
  #output:
Enter the number of keys to be inserted?9
Enter the size of hash tabel or (m)?9
Enter key:5
Enter key:28
Enter key:19
Enter key:15
Enter key:20
Enter key:33
Enter key:12
Enter key:17
Enter key:10
10
28
19
20
12
5
15
33
17
