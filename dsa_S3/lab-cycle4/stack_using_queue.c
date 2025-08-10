#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

// Simple fixed-size Queue implementation
typedef struct {
    int data[MAX];
    int front, rear;
} Queue;


void initQueue(Queue* q) {
    q->front = 0;
    q->rear = 0;
}


bool isEmptyQ(Queue* q){
    return q->front == q->rear;
}


bool isFullQ(Queue* q){
    return q->rear == MAX;
}


void enqueue(Queue* q, int x){
    if (!isFullQ(q))
        q->data[q->rear++] = x;
}


int dequeue(Queue* q){
    if (isEmptyQ(q))
        return -1;
    return q->data[q->front++];
}

// Stack built using two queues
Queue q1, q2;

void push(int x) {
    initQueue(&q2);
    enqueue(&q2, x);
    while (!isEmptyQ(&q1)) {
        enqueue(&q2, dequeue(&q1));
    }
    // Swap queues by copying q2 into q1
    q1 = q2;
}

void pop(){
    if (isEmptyQ(&q1)) {
        printf("Stack is empty.\n\n");
    } else {
        printf("Popped: %d\n\n", dequeue(&q1));
    }
}

void display(){
    if (isEmptyQ(&q1)) {
        printf("Stack is empty.\n\n");
        return;
    }
    // Display from top to bottom
    for (int i = q1.front; i < q1.rear; i++) {
        printf("%d\n", q1.data[i]);
    }
    printf("\n");
}

int main(void){
    initQueue(&q1);
    initQueue(&q2);

    printf("Menu\n1.Push\n2.Pop\n3.Display\n4.Exit\nChoice: ");

    while (1){
        int option, data;
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("Data: ");
                scanf("%d", &data);
                push(data);
                printf("\n");
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Enter valid input\n\n");
        }
    }
    return 0;
}
