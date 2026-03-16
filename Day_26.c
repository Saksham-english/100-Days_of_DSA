/*Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.*/
#include <stddef.h>

struct Node {
    int data;
    struct Node* next;
};

void removeLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;

    // Detect loop
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    // If no loop
    if (fast == NULL || fast->next == NULL)
        return;

    slow = head;

    if (slow == fast) {
        while (fast->next != slow)
            fast = fast->next;
    } 
    else {
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    fast->next = NULL;
}