#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int deque[MAX];
int front = -1, rear = -1;

// Check empty
int isEmpty() {
    return (front == -1);
}

// Check full
int isFull() {
    return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}

// push_front
void push_front(int x) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else if (front == 0) {
        front = MAX - 1;
    } else {
        front--;
    }

    deque[front] = x;
}

// push_back
void push_back(int x) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else if (rear == MAX - 1) {
        rear = 0;
    } else {
        rear++;
    }

    deque[rear] = x;
}

// pop_front
void pop_front() {
    if (isEmpty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", deque[front]);

    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }
}

// pop_back
void pop_back() {
    if (isEmpty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = MAX - 1;
    } else {
        rear--;
    }
}

// front element
void getFront() {
    if (isEmpty()) printf("-1\n");
    else printf("%d\n", deque[front]);
}

// back element
void getBack() {
    if (isEmpty()) printf("-1\n");
    else printf("%d\n", deque[rear]);
}

// size
void getSize() {
    if (isEmpty()) {
        printf("0\n");
        return;
    }
    if (rear >= front)
        printf("%d\n", rear - front + 1);
    else
        printf("%d\n", MAX - front + rear + 1);
}

// display deque
void display() {
    if (isEmpty()) {
        printf("Empty\n");
        return;
    }

    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        char op[20];
        scanf("%s", op);

        if (op[0] == 'p' && op[5] == 'f') {  // push_front
            int x;
            scanf("%d", &x);
            push_front(x);
        } 
        else if (op[0] == 'p' && op[5] == 'b') { // push_back
            int x;
            scanf("%d", &x);
            push_back(x);
        } 
        else if (op[0] == 'p' && op[1] == 'o' && op[4] == 'f') { // pop_front
            pop_front();
        } 
        else if (op[0] == 'p' && op[1] == 'o' && op[4] == 'b') { // pop_back
            pop_back();
        } 
        else if (op[0] == 'f') { // front
            getFront();
        } 
        else if (op[0] == 'b') { // back
            getBack();
        } 
        else if (op[0] == 's') { // size
            getSize();
        }
        else if (op[0] == 'd') { // display
            display();
        }
    }

    return 0;
}