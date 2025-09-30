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

// Insert at end (helper to create list)
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

// Insert before given key
struct Node* insertBefore(struct Node *head, int key, int data) {
    struct Node *temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node %d not found!\n", key);
        return head;
    }

    struct Node *newNode = createNode(data);

    newNode->next = temp;
    newNode->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = newNode;
    else
        head = newNode;   // new node becomes head

    temp->prev = newNode;

    printf("Inserted %d before %d\n", data, key);
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
    int n, i, val, key, newVal;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &val);
        head = insertEnd(head, val);
    }

    display(head);

    printf("Enter node data before which to insert: ");
    scanf("%d", &key);
    printf("Enter new value: ");
    scanf("%d", &newVal);

    head = insertBefore(head, key, newVal);

    display(head);

    return 0;
}
