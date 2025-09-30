#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

// Create new node
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Insert at front
struct Node* insertFront(struct Node *head, int data) {
    struct Node *newNode = createNode(data);

    if (head == NULL) 
        return newNode;

    newNode->next = head;
    head->prev = newNode;
    head = newNode;

    return head;
}

// Display forward
void displayForward(struct Node *head) {
    struct Node *temp = head;
    printf("Forward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Display backward
void displayBackward(struct Node *head) {
    struct Node *temp = head;

    if (temp == NULL) return;

    // go to last node
    while (temp->next != NULL) 
        temp = temp->next;

    printf("Backward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;
    int n, i, val;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &val);
        head = insertFront(head, val);
    }

    displayForward(head);
    displayBackward(head);

    return 0;
}
