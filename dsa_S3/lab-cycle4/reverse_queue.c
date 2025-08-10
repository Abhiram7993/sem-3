#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// initializing queue
#define MAX 50
int QUEUE[MAX];
int front = -1;
int rear = -1;

// initializing stack
int STACK[MAX];
int top = -1;

// fn prototyping
void flush(void);
void Enqueue(int data);
int Dequeue(void);
void Display(void);
int size(void);
bool IsEmpty(void);
void Reverse(void);
void push(int n);
int pop(void);


int main(void){
    printf("Menu\n1.Enqueue\n2.Dequeue\n3.Display\n4.Size\n5.Reverse\n6.Exit\n");
    while (1){
        int option;
        printf("Choice: ");
        scanf("%d", &option);
        flush();

        switch (option){
            case 1:
                int data;
                printf("Enter a data: ");
                scanf("%i", &data);
                flush();
                Enqueue(data);
                break;
            case 2:
                int n = Dequeue();
                printf("%i\n", n);
                break;
            case 3:
                Display();
                break;
            case 4:
                int m = size();
                if (m == -1){
                    printf("No elements in Queue\n");
                    break;
                }
                printf("%i\n", m);
                break;
            case 5:
                Reverse();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Enter valid input\n\n");
        }
    }
    return 1;
}


void flush(void){
    int c = getchar();
    while (c!='\n'&& c!=EOF){
        c = getchar();
    }
}


void Enqueue(int data){
    if (rear == MAX-1){
        printf("Overflow.\n\n");
        exit(1);
    }
    // adding data to the queue
    rear++;
    QUEUE[rear] = data;

    // If adding first element
    if (front == -1){
        front = 0;
    }
}


int Dequeue(void){
    if (IsEmpty()){
        printf("Queue is empty.\n\n");
        exit(1);
    }
    int data = QUEUE[front];

    if (front == rear){
        front = -1;
        rear = -1;
    }
    else{
        front++;
    }
    return data;
}


void Display(void){
    if (IsEmpty()){
        printf("Queue is empty, nothing to display");
        return;
    }

    for (int i=front; i<=rear; i++){
        printf("%i\t", QUEUE[i]);
    }
    printf("\n\n");
}

int size(void){
    if (IsEmpty()){
        return -1;
    }
    else{
        return (rear-front+1);
    } 
}


bool IsEmpty(void){
    return (front == -1); 
}


void Reverse(void){
    
    int n = size();
    if (n == -1){
        printf("Nothing to reverse.\n");
        return;
    }

    // Dequeing elements from Queue and Pushing to stack
    for (int i=0; i<n; i++){
        int data = Dequeue();
        push(data);
    }

    // poping elements from stack and Enqueing them to Queue
    for (int i=0; i<n; i++){
        int data = pop();
        Enqueue(data);
    }
}

void push(int n){
    if (top == MAX-1){
        printf("Stack is full.\n");
        exit(1);
    }
    top++;
    STACK[top] = n;
}


int pop(void){
    if (top == -1){
        printf("Stack underflow\n");
        exit(1);
    }
    int data = STACK[top];
    top--;
    return data;
}



