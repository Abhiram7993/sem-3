#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char url[50];
    struct Node *prev, *next;
};

struct Node* current = NULL;

// Create new node
struct Node* createNode(char *url) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->url, url);
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Visit new page
void visit(char *url) {
    struct Node* newPage = createNode(url);
    if (current) {
        current->next = newPage;
        newPage->prev = current;
    }
    current = newPage;
    printf("Visited: %s\n", current->url);
}

// Back
void back() {
    if (current && current->prev) {
        current = current->prev;
        printf("Back to: %s\n", current->url);
    } else
        printf("No previous page!\n");
}

// Forward
void forward() {
    if (current && current->next) {
        current = current->next;
        printf("Forward to: %s\n", current->url);
    } else
        printf("No forward page!\n");
}

// Show current
void show() {
    if (current)
        printf("Current page: %s\n", current->url);
    else
        printf("No pages opened!\n");
}

int main() {
    visit("google.com");
    visit("github.com");
    visit("chatgpt.com");

    back();
    show();

    forward();
    show();

    visit("stackoverflow.com");
    show();

    return 0;
}
