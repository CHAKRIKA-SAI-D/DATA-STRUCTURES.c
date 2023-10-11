//stacks in array

#include <stdio.h>

int a[5];
int top = -1;  // Initialize top to -1

void push(int value) {
    if (top == 4) {
        printf("stack overflow\n");
    } else {
        top++;
        a[top] = value;
    }
}

void pop() {
    if (top == -1) {
        printf("stack underflow\n");
    } else {
        printf("Deleted element: %d\n", a[top]);
        top--;
    }
}

void display() {
    if (top == -1) {
        printf("stack is empty\n");
    } else {
        for (int i = 0; i <= top; i++) {  // Changed i<top to i<=top
            printf("%d ", a[i]);  // Added a space for better formatting
        }
        printf("\n");  // Added a newline to separate the output
    }
}

int main() {
    int choice;
    int i=1;
    while (i!=0) {
        printf("Enter the choice:\n1: Push\n2: Pop\n3: Display\n4: Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int value;
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            }
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("exiting the program");
                i=0;  // Exiting the program
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
