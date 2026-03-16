#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, val;

    struct Node *head = NULL, *last = NULL, *temp;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {

        scanf("%d", &val);

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            last = newNode;
        } 
        else {
            last->next = newNode;
            last = newNode;
        }
    }

    // Make circular
    if(last != NULL)
        last->next = head;

    // Traverse circular linked list
    if(head != NULL) {
        temp = head;

        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while(temp != head);
    }

    return 0;
}