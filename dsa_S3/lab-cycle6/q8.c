#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// Delete smallest element
struct Node* deleteSmallest(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return head;
    }

    struct Node* temp = head;
    struct Node* minNode = head;

    while (temp != NULL) {
        if (temp->data < minNode->data)
            minNode = temp;
        temp = temp->next;
    }

    if (minNode == head)
        head = minNode->next;

    if (minNode->next != NULL)
        minNode->next->prev = minNode->prev;
    if (minNode->prev != NULL)
        minNode->prev->next = minNode->next;

    printf("Smallest element %d deleted.\n", minNode->data);
    free(minNode);
    return head;
}

// Display list
void display(struct Node* head) {
    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n, i, val;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &val);
        head = insertEnd(head, val);
    }

    display(head);

    head = deleteSmallest(head);

    display(head);

    return 0;
}
