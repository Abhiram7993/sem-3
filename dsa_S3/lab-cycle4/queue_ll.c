#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node* next;
}node;

void Enqueue(void);
void Dequeue(void);
void Display(void);
void peek(void);
void flush(void);


// initiating Linked List
node* front = NULL;
node* rear = NULL;


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
    while ((c!='\n')&&(c!=EOF)){
        c = getchar();
    }
}


void Enqueue(void){
    node* newnode = (node*)malloc(sizeof(node));
    printf("Enter data: ");
    scanf("%i", &(newnode->data));
    flush();
    newnode->next = NULL;

    // adding newnode to linked list
    if (rear == NULL){
        rear = newnode;
        front = newnode;
        return;
    }
    rear->next = newnode;
    rear = newnode;
}


void Dequeue(void){
    if (front == NULL){
        printf("Linked list is empty.\n");
        return;
    }
    node* temp = front;
    printf("%i\n", temp->data);

    if (front == rear){
        front = NULL, rear = NULL;
    }
    else{
        front = front->next;
    }
    free(temp);
} 


void Display(void){
    if (front == NULL){
        printf("Linked list is empty.\n");
        return;
    }

    node* traveller = front;
    while (traveller != NULL){
        printf("%i-> ", traveller->data);
        traveller = traveller->next; 
    }
    printf("NULL\n");
}


void peek(void){
    if (front == NULL){
        printf("Linked list is empty.\n");
        return;
    }
    printf("%i\n", front->data);
}