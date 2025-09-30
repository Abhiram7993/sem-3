#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Insert at end (helper to build list)
struct Node* insertEnd(struct Node *head, int data) {
    struct Node *newNode = createNode(data);
    if (head == NULL) return newNode;

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// Insert at given position
struct Node* insertAtPos(struct Node *head, int pos, int data) {
    struct Node *newNode = createNode(data);

    if (pos == 1) {  // insert at front
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        head = newNode;
        return head;
    }

    struct Node *temp = head;
    int i;
    for (i = 1; i < pos-1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position!\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;

    return head;
}

// Display list
void display(struct Node *head) {
    struct Node *temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;
    int n, i, val, pos, newVal;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &val);
        head = insertEnd(head, val);
    }

    display(head);

    printf("Enter position to insert (1-n): ");
    scanf("%d", &pos);
    printf("Enter new value: ");
    scanf("%d", &newVal);

    head = insertAtPos(head, pos, newVal);

    display(head);

    return 0;
}
