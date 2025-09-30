#include <stdio.h>

#define MAX 100

int bst[MAX]; // array to hold tree nodes

// Insert value into BST (array-based)
void insert(int val, int i) {
    if (i >= MAX) return;
    if (bst[i] == 0) {
        bst[i] = val;
        return;
    }
    if (val < bst[i]) insert(val, 2*i);
    else insert(val, 2*i+1);
}

// Inorder traversal
void inorder(int i) {
    if (i >= MAX || bst[i] == 0) return;
    inorder(2*i);
    printf("%d ", bst[i]);
    inorder(2*i+1);
}

// Preorder traversal
void preorder(int i) {
    if (i >= MAX || bst[i] == 0) return;
    printf("%d ", bst[i]);
    preorder(2*i);
    preorder(2*i+1);
}

// Postorder traversal
void postorder(int i) {
    if (i >= MAX || bst[i] == 0) return;
    postorder(2*i);
    postorder(2*i+1);
    printf("%d ", bst[i]);
}

int main() {
    int arr[] = {30, 20, 40, 15, 25, 35, 50, 5, 18, 45, 60};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < n; i++)
        insert(arr[i], 1);

    printf("Inorder: ");
    inorder(1);
    printf("\n");

    printf("Preorder: ");
    preorder(1);
    printf("\n");

    printf("Postorder: ");
    postorder(1);
    printf("\n");

    return 0;
}
