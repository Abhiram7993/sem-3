#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Node {
    char data;
    struct Node *left, *right;
};

// Stack for tree nodes
struct Stack {
    int top;
    struct Node* arr[100];
};

void push(struct Stack* s, struct Node* node) {
    s->arr[++s->top] = node;
}

struct Node* pop(struct Stack* s) {
    return s->arr[s->top--];
}

struct Node* newNode(char data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int isOperator(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/');
}

// Build expression tree from postfix
struct Node* constructTree(char postfix[]) {
    struct Stack s;
    s.top = -1;
    for(int i=0; postfix[i]; i++) {
        char c = postfix[i];
        if(isalnum(c)) {
            push(&s, newNode(c));
        } else if(isOperator(c)) {
            struct Node* node = newNode(c);
            node->right = pop(&s);
            node->left = pop(&s);
            push(&s, node);
        }
    }
    return pop(&s);
}

// Traversals
void preorder(struct Node* root) {  // prefix
    if(root) {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {  // postfix
    if(root) {
        postorder(root->left);
        postorder(root->right);
        printf("%c ", root->data);
    }
}

int main() {
    char postfix[] = "ab+cd-*";   // (a+b)*(c-d)

    struct Node* root = constructTree(postfix);

    printf("Prefix: ");
    preorder(root);
    printf("\n");

    printf("Postfix: ");
    postorder(root);
    printf("\n");

    return 0;
}
