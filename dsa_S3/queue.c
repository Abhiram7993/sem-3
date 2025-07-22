#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

// intializing queue
#define MAX 5
int QUEUE[MAX];
int rear = -1;   // Always point on the latest added/last element
int front = 0;   // Always points to the next element to be retreived

void flush(void);
void Enqueue(void);
void Dequeue(void);
void display(void);
void peek(void);
void size(void);
bool IsEmpty(void);


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
    if (rear == MAX-1){
        printf("Overflow.\n\n");
        return;
    }

    int data;
    printf("Enter a data: ");
    scanf("%i", &data);
    flush();

    // adding data to the queue
    rear++;
    QUEUE[rear] = data;
}


void Dequeue(void){
    if (IsEmpty()){
        printf("Queue is empty.\n\n");
        return;
    }

    printf("%i\n\n", QUEUE[front]);
    front++;
}


void display(void){
    if (IsEmpty()){
        printf("Queue is empty, nothing to display");
        return;
    }

    for (int i=front; i<=rear; i++){
        printf("%i\t", QUEUE[i]);
    }
    printf("\n\n");
}


void peek(void){
    if (IsEmpty()){
        printf("Nothing to peek.\n\n");
        return;
    }

    printf("%i\n\n", QUEUE[front]);
}


void size(void){
    if (IsEmpty()){
        printf("0\n\n");
        return;
    }

    printf("%i\n\n", rear-front+1);
}


bool IsEmpty(void){
    if (front > rear){
        if (front != 0){
            front = 0;
            rear = -1;
        }
        return true;
    }
    else{
        return false;
    }
}


