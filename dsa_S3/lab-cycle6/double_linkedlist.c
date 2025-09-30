#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node* prev;
    int value;
    struct node* next;
}node;

node* DLL = NULL;

void flush(void);
void insert(int n);
void display(void);


int main(void){
    int c;
    printf("1. Insert at end.\n2. Display\n3. Exit\n");
    while (1){
        printf("Enter choice: ");
        scanf("%i", &c);
        flush();

        switch (c){
            case 1:
                int n;
                printf("Enter Value to Insert: ");
                scanf("%i", &n);
                insert(n);
                break;
            
            case 2:
                display();
                break;

            case 3:
                exit(0);
                break;
            
            default:
                printf("Enter a valid input.");
        }
    }

    return 1;
}


void flush(void){
    int c = getchar();
    while (c!='\n' && c!=EOF){
        c = getchar();
    }
}


void insert(int n){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->value = n;
    newnode->next = NULL;

    if (DLL == NULL){
        newnode->prev = NULL;
        DLL = newnode;
    }
    else{
        node* temp = DLL;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
}


void display(void){
    if (DLL == NULL){
        printf("Nothing to display.\n");
        return;
    }
    node* temp = DLL;
    while (temp != NULL){
        printf("%i->", temp->value);
        temp = temp->next;
    }
    printf("\n");
}