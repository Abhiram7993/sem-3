/*
Note: 1 has higher priority, as values increases priority decreases.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// defining node
typedef struct node{
    int data;
    int priority;
    struct node* next;
}node;

// Initializing priority queue
node* P_QUEUE = NULL;

void insert(void);
void delete(void);
void peek(void);
void display(void);
void flush(void);


int main(void){
    
    int choice;
 
    printf("\n1 - Insert an element into queue");
    printf("\n2 - Delete an element from queue");
    printf("\n3 - peek queue element");
    printf("\n4 - Display elements");
    printf("\n5 - Exit");
 
    while (1)
    {
        printf("\nEnter your choice : ");    
        scanf("%d", &choice);
        flush();
 
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3: 
            peek();
            break;
        case 4:
            display();
            break;
        case 5: 
            exit(0);
        default: 
            printf("\nChoice is incorrect, Enter a correct choice");
        }
    }
    return 1;
}


void insert(void){
    int data, priority;
    printf("Enter data: ");
    scanf("%i", &data);
    flush();
    printf("Enter priority: ");
    scanf("%i", &priority);
    flush();

    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->priority = priority;
    newnode->next = NULL;

    // inserting newnode
    if (P_QUEUE == NULL || P_QUEUE->priority > priority){
        newnode->next = P_QUEUE;
        P_QUEUE = newnode;
    }
    else{
        node* traveller = P_QUEUE;
        while (traveller->next!=NULL && traveller->next->priority<priority){
            traveller = traveller->next;
        } 
        newnode->next = traveller->next;
        traveller->next = newnode;
    }
}


void delete(void){
    if (P_QUEUE == NULL){
        printf("Queue is empty.\n");
        return;
    }
    else {
        node* temp = P_QUEUE;
        P_QUEUE = P_QUEUE->next;
        printf("Highest priority value is %i\n", temp->data);
        free(temp);
    }
}


void peek(void){
    if (P_QUEUE == NULL){
        printf("Queue is empty.\n");
        return;
    }
    printf("Highest priority value is %i\n", P_QUEUE->data);
}


void display(void){
    if (P_QUEUE == NULL){
        printf("Queue is empty.\n");
        return;
    }
    node* traveller = P_QUEUE;
    while (traveller != NULL){
        printf("%i -> ", traveller->data);
        traveller = traveller->next;
    }
    printf("\n");
}


void flush(void){
    int c = getchar();
    while (c!='\n' && c!=EOF){
        c = getchar();
    }
}