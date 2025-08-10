#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node* next;
}node;

// initializing linked list
node* front = NULL;
node* rear = NULL;

// calling functions
void Enqueue(void);
void Dequeue(void);
void Display(void);
void peek(void);
void flush(void);
void freed(void); // For avoiding memory leak


int main(void){

    printf("Menu\n1.Enqueue\n2.Dequeue\n3.Display\n4.Peek\n5.Exit\n");
    while (1){
        int option;
        printf("Choice: ");
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
                Display();
                break;
            case 4:
                peek();
                break;
            case 5:
                freed();
                exit(0);
            default:
                printf("Enter valid input\n\n");
        }
    }
    return 1;
}


void Enqueue(void){
    int data;
    printf("Enter data: ");
    scanf("%i", &data);
    flush();

    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;

    if (rear == NULL){
        front = rear = newnode;
        rear->next = front;
    }
    else{
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }
}


void Dequeue(void){
    if (front == NULL){
        printf("Queue is Empty.\n");
        return;
    }
    node* temp = front;
    printf("%i\n", temp->data);

    if (front == rear){
        front = rear = NULL;
    }
    else{
        front = front->next;
        rear->next = front;
    }
    free(temp);
}


void Display(void){
    if (front == NULL){
        printf("Nothing to display.\n");
        return;
    }
    node* traveller = front;
    while (traveller != rear){
        printf("%i ->", traveller->data);
        traveller = traveller->next;
    }
    printf("%i\n", rear->data);
}


void peek(void){
    if (front == NULL){
        printf("Nothing to display.\n");
        return;
    }
    printf("%i\n", front->data);
}


void flush(void){
    int c = getchar();
    while (c!='\n'&& c!=EOF){
        c = getchar();
    }
}


void freed(void){
    if (front == NULL){
        return;
    }
    node* temp;
    while (front!=rear){
        temp = front;
        front = front->next;
        free(temp);
    }
    free(front);
}