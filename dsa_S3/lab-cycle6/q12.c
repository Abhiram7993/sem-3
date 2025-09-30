#include <stdio.h>
#include <stdlib.h>

struct Node {
    int size;
    int allocated;  // 1 = allocated, 0 = free
    struct Node *prev, *next;
};

struct Node* createNode(int size, int allocated) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->size = size;
    newNode->allocated = allocated;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insertEnd(struct Node* head, int size, int allocated) {
    struct Node* newNode = createNode(size, allocated);
    if (head == NULL) return newNode;

    struct Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// Display memory blocks
void display(struct Node* head) {
    printf("Memory Blocks:\n");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("[%d %s] -> ", temp->size, temp->allocated ? "ALLOC" : "FREE");
        temp = temp->next;
    }
    printf("NULL\n");
}

// Compaction
struct Node* compact(struct Node* head) {
    struct Node *temp = head, *freeList = NULL;

    while (temp != NULL) {
        struct Node* next = temp->next;

        if (temp->allocated == 0) {
            // detach free node
            if (temp->prev) temp->prev->next = temp->next;
            if (temp->next) temp->next->prev = temp->prev;
            if (temp == head) head = temp->next;

            // move node to freeList end
            temp->prev = temp->next = NULL;
            if (freeList == NULL)
                freeList = temp;
            else {
                struct Node* f = freeList;
                while (f->next) f = f->next;
                f->next = temp;
                temp->prev = f;
            }
        }
        temp = next;
    }

    // Attach freeList at the end
    if (head == NULL) return freeList;

    struct Node* end = head;
    while (end->next) end = end->next;
    end->next = freeList;
    if (freeList) freeList->prev = end;

    return head;
}

int main() {
    struct Node* head = NULL;

    // Example memory layout: ALLOC, FREE, ALLOC, FREE
    head = insertEnd(head, 100, 1); // allocated
    head = insertEnd(head, 50, 0);  // free
    head = insertEnd(head, 200, 1); // allocated
    head = insertEnd(head, 75, 0);  // free
    head = insertEnd(head, 300, 1); // allocated
    head = insertEnd(head, 150, 0); // free

    printf("Before Compaction:\n");
    display(head);

    head = compact(head);

    printf("\nAfter Compaction:\n");
    display(head);

    return 0;
}
