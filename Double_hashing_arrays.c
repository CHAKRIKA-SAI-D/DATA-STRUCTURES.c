//double hashing with fixed hash functions

#include <stdio.h>
#include <stdlib.h>

//here rehash function is h[x]=key%7 +1
int rehash(int data) {
    int h2 = (data % 7) + 1;
    return h2;
}

//for displaying the array
void display(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%5d\t : %5d\n", i, a[i]);
    }
}

int main() {
    int size;
    printf("Enter the size or (m) : ");
    scanf("%d", &size);
    int h[size];
    for (int i = 0; i < size; i++) {
        h[i] = 0;  
    }
    int n;
    printf("enter the no of keys: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int key;
        printf("enter key: ");
        scanf("%d", &key);
        int h1 = key % size;
        if (h[h1] == 0) {
            h[h1] = key;
        } else {
            int j = 1;
            int t = h1;
          
            //collision resolution technique
            while (h[t] != 0) { 
                t = (h1 + rehash(key) * j) % size;
                j++;
            }
            h[t] = key;
        }
    }
    display(h, size);
    return 0;
}

-------------------------------------------------------------------------------------------------------------------------------------
  #output:
Enter the size or (m) : 5
enter the no of keys: 4
enter key: 5
enter key: 1
enter key: 15
enter key: 20
    0    :     5
    1    :     1
    2    :    15
    3    :     0
    4    :    20
