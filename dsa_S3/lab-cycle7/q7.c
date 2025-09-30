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

// Count total nodes
int countNodes(struct Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Count leaf nodes
int countLeaf(struct Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return countLeaf(root->left) + countLeaf(root->right);
}

// Count internal nodes
int countInternal(struct Node* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 0; // leaf
    return 1 + countInternal(root->left) + countInternal(root->right);
}

int main() {
    int arr[] = {30, 20, 40, 15, 25, 35, 50, 5, 18, 45, 60};
    int n = sizeof(arr)/sizeof(arr[0]);

    struct Node* root = NULL;
    for (int i = 0; i < n; i++)
        root = insert(root, arr[i]);

    printf("Total nodes: %d\n", countNodes(root));
    printf("Leaf nodes: %d\n", countLeaf(root));
    printf("Internal nodes: %d\n", countInternal(root));

    return 0;
}
