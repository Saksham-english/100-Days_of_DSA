/*Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom

Example:
Input:
5
10 20 30 40 50
2

Output:
30 20 10  */
#include<stdio.h> 
# define MAX 100

stack[MAX] ;
int top = -1 ;

//push operation 
void push(int value)
{if( top ==MAX - 1 ){
    printf("OVERFLOW");
}
else{
    top++;
    stack[top]=value;
}
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        top--;
    }
}

void display(){
    if(top ==-1){
        printf("Stack is empty ");
    }
    else{
        for(int i=top;i>=0;i--){
            printf("%d",stack[i]);
        }
    }
}

int main(){
    int n,x,m;
    printf("no of elements ");
    scanf("%d",&n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        push(x);
    }

    printf("Enter no of pop ");
    scanf("%d", &m);

    // Perform pop operations
    for (int i = 0; i < m; i++) {
        pop();
    }

    // Display remaining stack
    display();

    return 0;
}
    

