#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

// Function prototypes
void flush(void);
void insertFront(void);
void insertRear(void);
void deleteFront(void);
void deleteRear(void);
void display(void);
bool isEmpty(void);

int main(void) {
    while (1) {
        int choice;
        printf("\n--- Double Ended Queue (Deque) ---\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        flush();

        switch (choice) {
            case 1: insertFront(); break;
            case 2: insertRear(); break;
            case 3: deleteFront(); break;
            case 4: deleteRear(); break;
            case 5: display(); break;
            case 6: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}

void flush(void) {
    int c = getchar();
    while (c != '\n' && c != EOF) {
        c = getchar();
    }
}

bool isEmpty(void) {
    return front == NULL;
}

void insertFront(void) {
    int value;
    printf("Enter value: ");
    scanf("%d", &value);
    flush();

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = front;

    if (isEmpty()) {
        rear = newNode;
    } else {
        front->prev = newNode;
    }
    front = newNode;
    printf("Inserted %d at front.\n", value);
}

void insertRear(void) {
    int value;
    printf("Enter value: ");
    scanf("%d", &value);
    flush();

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = rear;

    if (isEmpty()) {
        front = newNode;
    } else {
        rear->next = newNode;
    }
    rear = newNode;
    printf("Inserted %d at rear.\n", value);
}

void deleteFront(void) {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }
    struct Node *temp = front;
    printf("Deleted from front: %d\n", temp->data);

    front = front->next;
    if (front == NULL) {
        rear = NULL;
    } else {
        front->prev = NULL;
    }
    free(temp);
}

void deleteRear(void) {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }
    struct Node *temp = rear;
    printf("Deleted from rear: %d\n", temp->data);

    rear = rear->prev;
    if (rear == NULL) {
        front = NULL;
    } else {
        rear->next = NULL;
    }
    free(temp);
}

void display(void) {
    if (isEmpty()) {
        printf("Deque is empty.\n");
        return;
    }
    struct Node *temp = front;
    printf("Deque: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

