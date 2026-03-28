#include<stdio.h> 
#include<stdlib.h> 
struct Node  {
    int data ;
    struct node * next ;
} ; 

struct Node* front = NULL;
struct Node* rear = NULL;

// Enqueue operation
void enqueue(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if (rear == NULL) { // Queue is empty
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

// Dequeue operation
int dequeue() {
    if (front == NULL) {
        return -1; // Queue is empty
    }

    struct Node* temp = front;
    int value = temp->data;
    front = front->next;

    if (front == NULL) {
        rear = NULL; // Queue becomes empty
    }

    free(temp);
    return value;
}

// Main function
int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        char op[10];
        scanf("%s", op);

        if (op[0] == 'e') { // enqueue
            int x;
            scanf("%d", &x);
            enqueue(x);
        } else if (op[0] == 'd') { // dequeue
            printf("%d\n", dequeue());
        }
    }

    return 0;
}