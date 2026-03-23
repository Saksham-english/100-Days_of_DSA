#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Check if stack is empty
int isEmpty() {
    return top == NULL;
}

// Push function
void push(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

// Pop function
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow (Invalid Expression)\n");
        exit(1);   // stop program immediately
    }
    struct Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

// Evaluate postfix expression
int evaluate(char *exp) {
    int i = 0;

    while (exp[i] != '\0') {

        // Skip spaces
        if (exp[i] == ' ') {
            i++;
            continue;
        }

        // If digit (handle multi-digit numbers)
        if (isdigit(exp[i])) {
            int num = 0;
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            push(num);
        }
        else {
            // Check if enough operands exist
            if (top == NULL || top->next == NULL) {
                printf("Invalid Expression\n");
                exit(1);
            }

            int b = pop();
            int a = pop();

            switch (exp[i]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/':
                    if (b == 0) {
                        printf("Division by zero error\n");
                        exit(1);
                    }
                    push(a / b);
                    break;
                default:
                    printf("Invalid operator: %c\n", exp[i]);
                    exit(1);
            }
            i++;
        }
    }

    // Final result
    int result = pop();

    // If stack not empty → invalid expression
    if (!isEmpty()) {
        printf("Invalid Expression\n");
        exit(1);
    }

    return result;
}

// Main function
int main() {
    char exp[100];

    printf("Enter postfix expression: ");
    fgets(exp, sizeof(exp), stdin);

    int result = evaluate(exp);

    printf("Result = %d\n", result);

    return 0;
}