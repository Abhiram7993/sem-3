#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char word[50];
    char meaning[100];
    struct Node *left, *right;
};

// Create new node
struct Node* newNode(char *word, char *meaning) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    strcpy(node->word, word);
    strcpy(node->meaning, meaning);
    node->left = node->right = NULL;
    return node;
}

// Insert word into BST
struct Node* insert(struct Node* root, char *word, char *meaning) {
    if(root == NULL) return newNode(word, meaning);

    if(strcmp(word, root->word) < 0)
        root->left = insert(root->left, word, meaning);
    else if(strcmp(word, root->word) > 0)
        root->right = insert(root->right, word, meaning);
    else
        printf("Word '%s' already exists!\n", word);
    return root;
}

// Search for a word
struct Node* search(struct Node* root, char *word, int *cmp) {
    if(root == NULL) return NULL;
    (*cmp)++;
    if(strcmp(word, root->word) == 0)
        return root;
    else if(strcmp(word, root->word) < 0)
        return search(root->left, word, cmp);
    else
        return search(root->right, word, cmp);
}

// Inorder traversal (sorted order)
void inorder(struct Node* root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%s : %s\n", root->word, root->meaning);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int choice;
    char word[50], meaning[100];

    while(1) {
        printf("\n--- Dictionary Menu ---\n");
        printf("1. Insert Word\n2. Search Word\n3. Display Dictionary\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter word: ");
                scanf("%s", word);
                printf("Enter meaning: ");
                scanf(" %[^\n]", meaning); // read full line
                root = insert(root, word, meaning);
                break;

            case 2: {
                printf("Enter word to search: ");
                scanf("%s", word);
                int cmp = 0;
                struct Node* res = search(root, word, &cmp);
                if(res)
                    printf("Found! %s : %s (Comparisons: %d)\n", res->word, res->meaning, cmp);
                else
                    printf("Word not found! (Comparisons: %d)\n", cmp);
                break;
            }

            case 3:
                printf("\nDictionary (Sorted):\n");
                inorder(root);
                break;

            case 4:
                exit(0);
        }
    }
}
