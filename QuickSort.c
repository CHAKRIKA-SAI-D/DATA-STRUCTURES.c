#include <stdio.h>

void printArray(int A[],int n){
    for(int i=0;i<n;i++){
        printf("%d\t",A[i]);
    }
    printf("\n");
}

int  partition(int A[],int low,int high){
    int pivot=A[low];
    int i=low+1;
    int j=high;
    int temp;
    do{
    while(A[i]<=pivot){
        i++;
    }
    while(A[j]>pivot){
        j--;
    }
    if(i<j){
        temp=A[i];
        A[i]=A[j];
        A[j]=temp;
    }
    }while(i<j);
    //if condition fails swap a[j] with pivot
    temp=A[low];
    A[low]=A[j];
    A[j]=temp;
    //finally returning index of pivot after partition
    return j;
}

void quicksort(int A[],int low,int high){
    //index of pivot after partition
    int pind;
    if(low<high){
    pind=partition(A,low,high);
    //sorting left sub array
    quicksort(A,low,pind-1);
    //sorting left sub array
    quicksort(A,pind+1,high);
    }
}


int main()
{
    int A[]={54,26,93,17,77,31,44,55,20};
    int n=9;
    //Before sorting
    printArray(A,n);
    quicksort(A,0,n-1);
    //After sorting
    printArray(A,n);

    return 0;
}


-----------------------------------------------------------------------------------------------
  #ouput:
  54      26      93      17      77      31      44      55      20
  17      20      26      31      44      54      55      77      93
