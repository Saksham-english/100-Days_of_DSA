/*Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity */
#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push function
void push(char x) {
    stack[++top] = x;
}

// Pop function
char pop() {
    return stack[top--];
}

// Check precedence
int precedence(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}

int main() {
    char exp[MAX], result[MAX];
    int i = 0, j = 0;

    printf("Enter infix expression: ");
    scanf("%s", exp);

    while (exp[i] != '\0') {

        // If operand → add to output
        if (isalnum(exp[i])) {
            result[j++] = exp[i];
        }

        // If '(' → push
        else if (exp[i] == '(') {
            push(exp[i]);
        }

        // If ')' → pop till '('
        else if (exp[i] == ')') {
            while (stack[top] != '(') {
                result[j++] = pop();
            }
            pop(); // remove '('
        }

        // If operator
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(exp[i])) {
                result[j++] = pop();
            }
            push(exp[i]);
        }

        i++;
    }

    // Pop remaining operators
    while (top != -1) {
        result[j++] = pop();
    }

    result[j] = '\0';

    printf("Postfix: %s", result);
    return 0;
}