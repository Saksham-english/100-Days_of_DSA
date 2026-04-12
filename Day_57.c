#include <stdio.h>
#include <stdlib.h>

// ── Tree Node ──
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// ── Create Node ──
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// ── Queue for Level Order ──
struct Queue {
    struct TreeNode* data[1000];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = q->rear = 0;
}

void push(struct Queue* q, struct TreeNode* node) {
    q->data[q->rear++] = node;
}

struct TreeNode* pop(struct Queue* q) {
    return q->data[q->front++];
}

// ── Build Tree ──
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Queue q;
    initQueue(&q);

    struct TreeNode* root = newNode(arr[0]);
    push(&q, root);

    int i = 1;
    while (i < n) {
        struct TreeNode* curr = pop(&q);

        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            push(&q, curr->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            push(&q, curr->right);
        }
        i++;
    }
    return root;
}

// ── Mirror Tree ──
void mirror(struct TreeNode* root) {
    if (root == NULL) return;

    // swap left and right
    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

// ── Inorder Traversal ──
void inorder(struct TreeNode* root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

// ── Main ──
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, n);

    mirror(root);        // convert to mirror
    inorder(root);       // print inorder

    return 0;
}