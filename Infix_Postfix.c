//Infix to Postfix expressions

#include <stdio.h>
#include <string.h>

int a[20];
int top = -1;

//To push the element to stack
//stack here considered as a
void push(char y) {
    top++;
    a[top]=y; 
}

//delete function from a
char pop() {
    char x=a[top];
    top--;
    return x; 
}

//This is to check the function's element to detect what type of element it is
int check(char x) {
    //for operators
    if (x == '-' || x == '+' || x == '%' || x == '/' || x == '*' || x == '^') {
        return 1;
    } else if (x == '(' || x == ')') { //for brackets
        return 2;
    } else {  //for operands
        return 0;
    }
}
int precedence(char x) {
    if (x == '^') return 3;
    if (x == '*' || x == '/'|| x=='%') return 2;
    if (x == '+' || x == '-') return 1;
    return 0;
}
int main() {
    int n;
    printf("Enter the size of the string: ");
    scanf("%d", &n);
    char str[n];
    char result[n];
    int s = 0;
    printf("Enter the string: ");
    scanf("%s", str);
    for (int i = 0; i < n; i++) { 
        if (check(str[i]) == 0) {
            result[s] = str[i];
            s++;
        } else {
            if (str[i] == '(') {
                push(str[i]);
            } else if (str[i] == ')') {
                while (top >= 0 && a[top] != '(') {
                    result[s] = pop();
                    s++;
                }
                if (top >= 0 && a[top] == '(') {
                    pop(); 
                }
            } else {
                //this while loop works till the given conditions are true
                while (top >= 0 && (precedence(a[top]) >= precedence(str[i]))) { 
                    result[s] = pop();
                    s++;
                }
                push(str[i]);
            }
        }
    }

    // Pop any remaining operators from the stack
    while (top >= 0) {
        result[s] = pop();
        s++;
    }

    result[s] = '\0'; // Null-terminate the result

    printf("Postfix expression: %s\n", result);

    return 0;
}

---------------------------------------------------------------------------------------------------------------------------------

  #output:
  Enter the size of the string: 9
  Enter the string: a+(b+c*d)
  Postfix expression: abcd*++
