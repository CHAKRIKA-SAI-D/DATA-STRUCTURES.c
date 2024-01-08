#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head, *tail;
struct node *head1, *tail1;

struct node *create(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(int data) {
    struct node *x = create(data);
    if (head == NULL) {
        head = x;
        tail = x;
    } else {
        tail->next = x;
        tail = x;
    }
}

void insert1(int data) {
    struct node *y = create(data);
    if (head1 == NULL) {
        head1 = y;
        tail1 = y;
    } else {
        tail1->next = y;
        tail1 = y;
    }
}

//merging two sorted lists
void mergeLists() {
    struct node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head1;
}

//sorting main list
void sort() {
    struct node *current = head;
    struct node *index = NULL;
    int temp;

    if (head == NULL) {
        return;
    } else {
        while (current != NULL) {
            index = current->next;

            while (index != NULL) {
                if (current->data > index->data) {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

void print() {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}

int main(void) {
    insert(1);
    insert(6);
    insert(7);
    insert(9);
    insert(10);
    insert1(2);
    insert1(3);
    insert1(4);
    insert1(11);
    mergeLists();
    sort();
    print();
    return 0;
}

-----------------------------------------------------------------------------------------------------------------
  #output:
  1       2       3       4       6       7       9       10      11
  
