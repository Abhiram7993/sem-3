#include <stdio.h>
#include <stdlib.h>

// Node definition
struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert into BST
struct Node* insert(struct Node* root, int val) {
    if (root == NULL) return createNode(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// Queue for Level Order
struct Node* queue[100];
int front = 0, rear = 0;

void enqueue(struct Node* n) { queue[rear++] = n; }
struct Node* dequeue() { return queue[front++]; }
int isEmpty() { return front == rear; }

// Level Order Traversal
void levelOrder(struct Node* root) {
    if (!root) return;
    enqueue(root);
    while (!isEmpty()) {
        struct Node* temp = dequeue();
        printf("%d ", temp->data);
        if (temp->left) enqueue(temp->left);
        if (temp->right) enqueue(temp->right);
    }
}

int main() {
    int arr[] = {30, 20, 40, 15, 25, 35, 50, 5, 18, 45, 60};
    int n = sizeof(arr)/sizeof(arr[0]);

    struct Node* root = NULL;
    for (int i = 0; i < n; i++)
        root = insert(root, arr[i]);

    printf("Level Order: ");
    levelOrder(root);
    printf("\n");

    return 0;
}
