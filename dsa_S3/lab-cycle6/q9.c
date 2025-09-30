#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node *front = NULL, *rear = NULL;

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Insert at front
void insertFront(int data) {
    struct Node* newNode = createNode(data);
    if (front == NULL) {
        front = rear = newNode;
    } else {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
    printf("%d inserted at front.\n", data);
}

// Insert at rear
void insertRear(int data) {
    struct Node* newNode = createNode(data);
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        newNode->prev = rear;
        rear = newNode;
    }
    printf("%d inserted at rear.\n", data);
}

// Delete from front
void deleteFront() {
    if (front == NULL) {
        printf("Deque is empty!\n");
        return;
    }
    struct Node* temp = front;
    printf("%d deleted from front.\n", temp->data);

    front = front->next;
    if (front != NULL)
        front->prev = NULL;
    else
        rear = NULL; // list became empty
    free(temp);
}

// Delete from rear
void deleteRear() {
    if (rear == NULL) {
        printf("Deque is empty!\n");
        return;
    }
    struct Node* temp = rear;
    printf("%d deleted from rear.\n", temp->data);

    rear = rear->prev;
    if (rear != NULL)
        rear->next = NULL;
    else
        front = NULL; // list became empty
    free(temp);
}

// Display deque
void display() {
    struct Node* temp = front;
    printf("Deque: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\n--- Deque Menu ---\n");
        printf("1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: printf("Enter value: "); scanf("%d", &val); insertFront(val); break;
            case 2: printf("Enter value: "); scanf("%d", &val); insertRear(val); break;
            case 3: deleteFront(); break;
            case 4: deleteRear(); break;
            case 5: display(); break;
            case 6: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
