#include <stdio.h>
#include <stdlib.h>

// array for saving elements
#define MAX 100
int array[MAX];
int size;

// Queue for saving max element in each windows
int QUEUE[MAX];
int front = -1;
int rear = -1;

void flush(void);
void sliding_window(int k);
int sizeofQ(void);
int Dequeue(void);
void Enqueue(int n);


int main(void){
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
    // setting up array
    printf("Enter number of elements in array: ");
    scanf("%i", &size);
    flush();
    if (!(size>0)){
        printf("Invalid input.\n");
        exit(1);
    }
    int i=0;
    while (i<size){
        printf("Enter data: ");
        scanf("%i", &(array[i]));
        flush();
        i++;
    }

    int k;
    printf("Size of window: ");
    scanf("%i", &k);
    flush();
    sliding_window(k);

    int n = sizeofQ();
    printf("maximum elements of the sliding windows are: \n");
    for (int j=0; j<n; j++){
        printf("%i\t ", Dequeue());
    }
    printf("\n");

    return 0;
}


void sliding_window(int k){
    for (int i=0; i<(size-k+1); i++){
        int max;
        int flag = 0;
        for (int j=i; j<(i+k); j++){
            if (!flag){
                max = array[j];
                flag = 1;
            }
            else{
                if (array[j] > max){
                    max = array[j];
                }
            }
        }
        Enqueue(max);
    }
}


void flush(void){
    int c = getchar();
    while (c!='\n' && c!=EOF){
        c = getchar();
    }
}


int sizeofQ(void){
    return (rear-front+1);
}


void Enqueue(int n){
    if (rear == MAX-1){
        printf("stack Overflow.\n");
        exit(1);
    }
    rear++;
    QUEUE[rear] = n;

    if (front == -1){
        front++;
    }
}


int Dequeue(void){
    if (front == -1){
        printf("Stack Underflow.\n");
        exit(1);
    }
    int data = QUEUE[front];
    if (front == rear){
        front = rear = -1;
    }
    else{#include <stdio.h>
#include <stdlib.h>

// array for saving elements
#define MAX 100
int array[MAX];
int size;

// Queue for saving max element in each windows
int QUEUE[MAX];
int front = -1;
int rear = -1;

void flush(void);
void sliding_window(int k);
int sizeofQ(void);
int Dequeue(void);
void Enqueue(int n);


int main(void){
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

// Simple fixed-size Queue implementation
typedef struct {
    int data[MAX];
    int front, rear;
} Queue;

#include <stdio.h>
#include <stdlib.h>

// array for saving elements
#define MAX 100
int array[MAX];
int size;

// Queue for saving max element in each windows
int QUEUE[MAX];
int front = -1;
int rear = -1;

void flush(void);
void sliding_window(int k);
int sizeofQ(void);
int Dequeue(void);
void Enqueue(int n);


int main(void){
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
    // setting up array
    printf("Enter number of elements in array: ");
    scanf("%i", &size);
    flush();
    if (!(size>0)){
        printf("Invalid input.\n");
        exit(1);
    }
    int i=0;
    while (i<size){
        printf("Enter data: ");
        scanf("%i", &(array[i]));
        flush();
        i++;
    }

    int k;
    printf("Size of window: ");
    scanf("%i", &k);
    flush();
    sliding_window(k);

    int n = sizeofQ();
    printf("maximum elements of the sliding windows are: \n");
    for (int j=0; j<n; j++){
        printf("%i\t ", Dequeue());
    }
    printf("\n");

    return 0;
}


void sliding_window(int k){
    for (int i=0; i<(size-k+1); i++){
        int max;
        int flag = 0;
        for (int j=i; j<(i+k); j++){
            if (!flag){
                max = array[j];
                flag = 1;
            }
            else{
                if (array[j] > max){
                    max = array[j];
                }
            }
        }
        Enqueue(max);
    }
}


void flush(void){
    int c = getchar();
    while (c!='\n' && c!=EOF){
        c = getchar();
    }
}


int sizeofQ(void){
    return (rear-front+1);
}
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
    // setting up array
    printf("Enter number of elements in array: ");
    scanf("%i", &size);
    flush();
    if (!(size>0)){
        printf("Invalid input.\n");
        exit(1);
    }
    int i=0;
    while (i<size){
        printf("Enter data: ");
        scanf("%i", &(array[i]));
        flush();
        i++;
    }

    int k;
    printf("Size of window: ");
    scanf("%i", &k);
    flush();
    sliding_window(k);

    int n = sizeofQ();
    printf("maximum elements of the sliding windows are: \n");
    for (int j=0; j<n; j++){
        printf("%i\t ", Dequeue());
    }
    printf("\n");

    return 0;
}


void sliding_window(int k){
    for (int i=0; i<(size-k+1); i++){
        int max;
        int flag = 0;
        for (int j=i; j<(i+k); j++){
            if (!flag){
                max = array[j];
                flag = 1;
            }
            else{
                if (array[j] > max){
                    max = array[j];
                }
            }
        }
        Enqueue(max);
    }
}


void flush(void){
    int c = getchar();
    while (c!='\n' && c!=EOF){
        c = getchar();
    }
}


int sizeofQ(void){
    return (rear-front+1);
}
        front++;
    }
    return data;
}
