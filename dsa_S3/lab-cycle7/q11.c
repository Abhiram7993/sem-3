#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left, *right;
};

struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int key) {
    if(!root) return newNode(key);
    if(key < root->key) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}

struct Node* buildBST(int preorder[], int n) {
    struct Node* root = NULL;
    for(int i=0; i<n; i++)
        root = insert(root, preorder[i]);
    return root;
}

void inorder(struct Node* root) {
    if(root) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main() {
    int preorder[] = {30,20,15,5,18,25,40,35,50,45,60};
    int n = sizeof(preorder)/sizeof(preorder[0]);

    struct Node* root = buildBST(preorder, n);

    printf("Inorder traversal (should be sorted):\n");
    inorder(root);
    return 0;
}