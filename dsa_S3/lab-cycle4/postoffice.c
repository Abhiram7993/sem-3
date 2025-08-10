// Note: Lower priority higher prefernce
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char name[50];
    int priority;
    struct node* next;
}node;

// declaring priority Queue
node* PRIORITY_QUEUE;

// fn declaring
void Enqueue(void);
void Dequeue(void);
void Display(void);
void peek(void);
void freed(void);
void flush(void);


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
                break;
            default:
                printf("Enter valid input\n\n");
        }
    }
    return 1;
}


void Enqueue(void){
    node* newnode = (node*)malloc(sizeof(node));
    printf("Enter Name: ");
    // reading name
    if (fgets(newnode->name, 50*sizeof(char), stdin)){
        newnode->name[strcspn(newnode->name, "\n")] = '\0';
    }

    // scaning priority
    printf("Differently Abled-1/Senior Citizen-2/Defence Personnel-3/Ordinary-4\n");
    int priority;
    int flag = 0;

    while (1){
        if (flag){
            break;
        }
        printf("Enter priority: ");
        scanf("%i", &priority);
        flush();
        
        switch(priority){
            case 1:
                flag = 1;
                break;
            case 2:
                flag = 1;
                break;
            case 3:
                flag = 1;
                break;
            case 4:
                flag = 1;
                break;
            default:
                printf("Enter a valid priority\n");
                continue;
        }
    }

    newnode->priority = priority;
    newnode->next = NULL;

    if (PRIORITY_QUEUE == NULL || PRIORITY_QUEUE->priority > newnode->priority){
        newnode->next = PRIORITY_QUEUE;
        PRIORITY_QUEUE = newnode;
    }
    else{
        node* traveller = PRIORITY_QUEUE;
        while ((traveller->next != NULL)&&(traveller->next->priority < newnode->priority)){
            traveller = traveller->next;
        }
        newnode->next = traveller->next;
        traveller->next = newnode;
    }
}


void Dequeue(void){
    if (PRIORITY_QUEUE == NULL){
        printf("Queue is Empty\n");
        return;
    }
    printf("%s\n", PRIORITY_QUEUE->name);
    node* temp = PRIORITY_QUEUE;
    if (PRIORITY_QUEUE->next == NULL){
        PRIORITY_QUEUE = NULL;
    }
    else{
        PRIORITY_QUEUE = PRIORITY_QUEUE->next;
    }
    free(temp);
}


void Display(void){
    if (PRIORITY_QUEUE == NULL){
        printf("QUEUE is empty.\n");
        return;
    } 
    
    node* traveller = PRIORITY_QUEUE;
    while (traveller != NULL){
        printf("%s ->", traveller->name);
        traveller = traveller->next;
    }
    printf("NULL\n");
}


void peek(void){
    if (PRIORITY_QUEUE == NULL){
        printf("QUEUE is empty.\n");
        return;
    }

    printf("%s\n", PRIORITY_QUEUE->name);
}


void freed(void){
    if (PRIORITY_QUEUE == NULL){
        return;
    }
    else{
        node* temp;
        while (PRIORITY_QUEUE != NULL){
            temp = PRIORITY_QUEUE;
            PRIORITY_QUEUE = PRIORITY_QUEUE->next;
            free(temp);
        }
    }
}


void flush(void){
    int c = getchar();
    while(c!='\n' && c!=EOF){
        c = getchar();
    }
}