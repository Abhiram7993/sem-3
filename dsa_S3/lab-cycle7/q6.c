#include <stdio.h>
#include <stdlib.h>

// Node definition
struct Node {
    int data;
    struct Node *left, *right;
};

// Create node
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

// Find height of BST
int height(struct Node* root) {
    if (root == NULL) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return 1 + (lh > rh ? lh : rh);
}

int main() {
    int arr[] = {30, 20, 40, 15, 25, 35, 50, 5, 18, 45, 60};
    int n = sizeof(arr)/sizeof(arr[0]);

    struct Node* root = NULL;
    for (int i = 0; i < n; i++)
        root = insert(root, arr[i]);

    printf("Height of BST: %d\n", height(root));

    return 0;
}
