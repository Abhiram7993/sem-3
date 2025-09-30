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

// Search key and count comparisons
void search(struct Node* root, int key) {
    int comparisons = 0;
    struct Node* temp = root;
    while (temp != NULL) {
        comparisons++;
        if (key == temp->data) {
            printf("Key %d found.\n", key);
            printf("Comparisons made: %d\n", comparisons);
            return;
        } else if (key < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    printf("Key %d not found.\n", key);
    printf("Comparisons made: %d\n", comparisons);
}

int main() {
    int arr[] = {30, 20, 40, 15, 25, 35, 50, 5, 18, 45, 60};
    int n = sizeof(arr)/sizeof(arr[0]);

    struct Node* root = NULL;
    for (int i = 0; i < n; i++)
        root = insert(root, arr[i]);

    int key;
    printf("Enter key to search: ");
    scanf("%d", &key);

    search(root, key);

    return 0;
}
