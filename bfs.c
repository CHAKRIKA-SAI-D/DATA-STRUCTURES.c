#include <stdio.h>

int queue[100];
int front, rear = 0;

void push(int x) {
    queue[rear] = x;
    rear++;
}

void pop() {
    queue[front] = 0;
    front++;
}

int main() {
    int n;
    printf("Enter size: ");
    scanf("%d", &n);

    int visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Enter the matrix : ");
    int graph[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    push(1);
    visited[0] = 1;

    while (front != rear) {
        int current = queue[front];
        pop();
        printf("%d ", current); // Print the visited node

        for (int i = 0; i < n; i++) {
            if ((graph[current - 1][i] == 1) && (visited[i] == 0)) {
                visited[i] = 1;
                push(i + 1);
            }
        }
    }

    return 0;
}



-----------------------------------------------------------------------------------------------------------------------------------
  #output
Enter size: 3
Enter the matrix : 0 1 0
1 0 1
0 1 0
0 1 0

1 0 1

0 1 0
1 2 3 
