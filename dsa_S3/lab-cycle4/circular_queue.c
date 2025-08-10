#include <stdio.h>
#include <stdbool.h>

// intializing circular queue
#define MAX 5
int CIRCULAR_QUEUE[MAX];
int rear = -1;
int front = -1;


void flush(void);
void Enqueue(void);
void Dequeue(void);
void display(void);
void size(void);
void peek(void);
bool IsEmpty(void);
bool IsFull(void);


int main(void){
    while (1){
        int option;
        printf("Menu\n1.Enqueue\n2.Dequeue\n3.Display\n4.Peek\n5.Size\n6.Exit\nChoice: ");
        scanf("%d", &option);
        flush();

        switch (option){
            case 1:
                Enqueue();
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                size();
                break;
            case 6:
                exit(0);
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


void Enqueue(void){
    if (IsFull()){
        printf("Queue Overflow.\n\n");
        return;
    }
    int data;
    printf("Enter data: ");
    scanf("%i", &data);
    flush();

    if (IsEmpty()){
        rear = front = 0;
        CIRCULAR_QUEUE[rear] = data;
    }
    else {
        rear = (rear + 1)%5;
        CIRCULAR_QUEUE[rear] = data;
    }
}


void Dequeue(void){
    if (IsEmpty()){
        printf("Queue Underflow\n\n");;
        return;
    }
    if (rear == front){
        int data = CIRCULAR_QUEUE[front];
        rear = front = -1;
        printf("%i\n\n", data);
        return;
    }
    else{
        int data = CIRCULAR_QUEUE[front];
        front = (front + 1)%MAX;
        printf("%i\n\n", data);
    }
}


void display(void){
    if (IsEmpty()){
        printf("Nothing to display.\n\n");
        return;
    }
    if (front == rear){
        printf("%i\n\n", CIRCULAR_QUEUE[front]);
    }
    else{
        for (int i=front; i!=rear; i=(i+1)%MAX){
            printf("%i\n", CIRCULAR_QUEUE[i]);
        }
        printf("%i\n\n", CIRCULAR_QUEUE[rear]);
    }
}


void size(void){
    if (IsEmpty()){
        printf("0\n\n");
        return;
    }
    if (front == rear){
        printf("1\n\n");
        return;
    }
    else{
        int count = 1;
        for (int i=front; i!=rear; i=(i+1)%MAX){
            count++;
        }
        printf("%i\n\n", count);
    }
}


void peek(void){
    if (IsEmpty()) {
        printf("add some elements.\n\n");
        return;
    }
    printf("%i", CIRCULAR_QUEUE[front]);
}


bool IsEmpty(void){
    return (front == -1);
}


bool IsFull(void){
    return ((rear + 1)%MAX == front);
}