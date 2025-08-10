// Input restricted
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Initialising Queue
#define MAX 10
int DEQUEUE[MAX];
int front = -1;
int rear = -1;

// declaring functions
void InsertRear(void);
void DeleteFront(void);
void DeleteRear(void);
bool IsFull(void);
bool IsEmpty(void);
void Display(void);
void PeekFront(void);
void PeekRear(void);
void flush(void);


int main(void){
    printf("Menu\n1.InsertatRear\n2.DeleteatFront\n3.DeleteatRear\n4.Display\n5.PeekFront\n6.PeekRear\n7.Exit\n");
    while (1){
        int option;
        printf("Choice: ");
        scanf("%d", &option);
        flush();

        switch (option){
            case 1:
                InsertRear();
                break;
            case 2:
                DeleteFront();
                break;
            case 3:
                DeleteRear();
                break;
            case 4:
                Display();
                break;
            case 5:
                PeekFront();
                break;
            case 6:
                PeekRear();
                break;
            case 7:
                exit(0);
            default:
                printf("Enter valid input\n\n");
        }
    }
    return 1;    
}


void InsertRear(void){
    if (IsFull()){
        printf("Queue is Full.\n");
        return;
    }

    int data;
    printf("Enter data: ");
    scanf("%i", &data);
    flush();
    if (IsEmpty()){
        front = rear = 0;
        DEQUEUE[rear] = data;
        return;
    }
    else{
        rear = (rear+1)%MAX;
        DEQUEUE[rear] = data;
    }
}


void DeleteFront(void){
    if (IsEmpty()){
        printf("Queue is Empty.\n");
        return;
    }
    printf("%i\n", DEQUEUE[front]);
    if (front == rear){
        front = rear = -1;
        return;
    }
    front = (front+1)%MAX;
}


void DeleteRear(void){
    if (IsEmpty()){
        printf("Queue is Empty.\n");
        return;
    }

    printf("%i\n", DEQUEUE[rear]);
    if (rear == front){
        front = rear = -1;
        return;
    }
    if (rear == 0){
        rear = MAX-1;
        return;
    }
    rear = rear-1;
}


bool IsFull(void){
    return ((rear+1)%MAX == front);
}


bool IsEmpty(void){
    return ((front == -1) && (rear == -1));
}


void Display(void){
    if (IsEmpty()){
        printf("Nothing to display.\n");
        return;
    }
    for (int i=front; i!=rear; i=(i+1)%MAX){
        printf("%i\t", DEQUEUE[i]);
    }
    printf("%i\n", DEQUEUE[rear]);
}


void PeekFront(void){
    if (IsEmpty()){
        printf("Nothing to display.\n");
        return;
    }
    printf("%i\n", DEQUEUE[front]);
}


void PeekRear(void){
    if (IsEmpty()){
        printf("Nothing to display.\n");
        return;
    }
    printf("%i\n", DEQUEUE[rear]);
}


void flush(void){
    int c = getchar();
    while (c!='\n' && c!=EOF){
        c = getchar();
    }
}