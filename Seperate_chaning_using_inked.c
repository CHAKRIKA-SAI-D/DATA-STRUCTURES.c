#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

void display(struct node* hash[], int n) {
    for(int i = 0; i < n; i++) {
        struct node* temp = hash[i];
        if(temp == NULL) {
            printf("No Element placed");
            printf("\n");
        }
        else {
            while(temp != NULL) {
                printf("%d\t", temp->data);
                temp = temp->next;
            }
            printf("\n");
        }
    }
}

int main() {
    int n;
    printf("Enter the size of the hash table or (m) : ");
    scanf("%d", &n);

    // Initialize the hash table as an array of pointers to struct node
    struct node* hash[n];

    int z;
    printf("Enter the number of elements to be inserted: ");
    scanf("%d", &z);

    for(int i = 0; i < n; i++) {
        hash[i] = NULL;  // Initialize each element in the hash table to NULL
    }

    for(int i = 0; i < z; i++) {
        int x;
        printf("Enter the element: ");
        scanf("%d", &x);
        int y = x % n;

        // Create a new node
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = x;
        newNode->next = NULL;

        // Insert the new node at the beginning of the linked list
        if (hash[y] == NULL) {
            hash[y] = newNode;
        } else {
            newNode->next = hash[y];
            hash[y] = newNode;
        }
    }

    display(hash, n);

    return 0;
}---------------------------------------------------------------------------------------------------------------------------------------------------------------

  #output:
  er the size of the hash table or (m) : 7
Enter the number of elements to be inserted: 7
Enter the element: 70
Enter the element: 85
Enter the element: 92
Enter the element: 12
Enter the element: 0=
Enter the element: Enter the element: 0 0       0       70
92      85
No Element placed
No Element placed
No Element placed
12
No Element placed
  
