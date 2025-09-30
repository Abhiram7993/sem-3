#include <stdio.h>
#include <stdlib.h>

// BST Node
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

// Find minimum
int findMin(struct Node* root) {
    if (root == NULL) {
        printf("BST is empty!\n");
        return -1;
    }
    while (root->left != NULL)
        root = root->left;
    return root->data;
}

// Find maximum
int findMax(struct Node* root) {
    if (root == NULL) {
        printf("BST is empty!\n");
        return -1;
    }
    while (root->right != NULL)
        root = root->right;
    return root->data;
}

int main() {
    int arr[] = {30, 20, 40, 15, 25, 35, 50, 5, 18, 45, 60};
    int n = sizeof(arr)/sizeof(arr[0]);

    struct Node* root = NULL;
    for (int i = 0; i < n; i++)
        root = insert(root, arr[i]);

    printf("Minimum key: %d\n", findMin(root));
    printf("Maximum key: %d\n", findMax(root));

    return 0;
}
