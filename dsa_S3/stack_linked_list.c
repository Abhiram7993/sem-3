#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Our linked list will be like a menu.
We can add elements, pop elements, display elements.
Since its stack implementation of linked list, so it follows LIFO. Display and pop will be in this order.
A node will store 2 things Name of the student and roll no.
When one hit pop or exit, all memories must be freed. */

// node
typedef struct node{
    char name[30];
    int rno;
    struct node* next;
}node;

// initializing linked list
node* top = NULL;

void push(void);
void pop(void);
void display(void);
void free_list(void);
void flush(void);


int main(void){
    // defining a menu, note 0 means False, all other is True
    int n;
    while(1){
        
        printf("1. Add data to linked list\n"
               "2. Pop data from linked list\n"
               "3. Display datas in linked list\n"
               "4. Exit the program\n"
               "Choice: ");
        scanf("%i", &n);
        flush();   // since \n is not readed by scanf, to avoid it we will use flush().

        switch (n){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Freeing the memory ...\nExited.\n");
                free_list();
                exit(0);
                break;
            default:
                printf("Enter a valid digit\n\n");
        }
    }
    return 1;
}


// This fn will not return anything, it will prompt for data
// and add that data in the linked list.
void push(void){

    // a new node
    node* temp = (node*) malloc(sizeof(node));
    // If space allocation failed then maloc returns NULL.
    // space is not allocated for node, then there is no meaning for further steps.
    if (temp == NULL){
        printf("Space allocation failed, element is not pushed\n\n");
        return;
    }
    
    // reading name, since we are reading string, we will use fgets()
    printf("Enter Name: ");
    // temp->name is an array of 30 character. 
    // So when we call it, the return value will be the address of 1st byte.
    // temp->name will be considered as array not pointer variable  
    if (fgets(temp->name, sizeof(temp->name), stdin)){
        // replacing \n with \0 using strcspn, note that arg of strcspn are strings.
        // Since fgets read \n too, we dont need to flush here.
        temp->name[strcspn(temp->name, "\n")] = '\0';
    }
    
    // reading Roll no
    printf("Enter Roll no: ");
    scanf("%i", &(temp->rno));
    flush();  // As scanf didnt read \n. So to flush that.
    
    
    // Adding node to linked list
    // checking whether its first element or not
    if (top == NULL){
        temp->next = NULL;
        top = temp;
    }
    else{
        temp->next = top;
        top = temp;
    }
    printf("Datas are pushed to linked list.\n\n");
    return;
}


void pop(void){
    // If linked list is empty
    if (top == NULL){
        printf("No datas to pop, linked list is empty.\n\n");
        return;
    }
    // accessing datas
    printf("Name: %s\n", top->name);
    printf("Roll no: %i\n\n", top->rno);

    // freeing the data and adjusting pointer to next data
    node* temp = top;
    top = top->next;
    free(temp);
}


void display(void){
    // If linked list is empty
    if (top == NULL){
        printf("Linked list is empty, nothing to display\n\n");
        return;
    }
    // displaying data
    node* iterator = top;
    while (iterator != NULL){
        printf("Name: %s\n", iterator->name);
        printf("Roll no: %i\n\n", iterator->rno);
        iterator = iterator->next;
    }
}


void free_list(void){
    // If top points to null, then no memory is to be freed 
    if (top == NULL){
        return;
    }
    // Something is in linked list, lets free it.
    node* iterator;
    while (top != NULL){
        iterator = top;
        top = top->next;
        free(iterator);
    }
}


void flush(void){
    // Its used to flush characters including one EOF or \n terminal
    // EOF will return by getchar() when cntrl + D is pressed in terminal, or when it reaches last while reading a file.
    // When nothing to read in a terminal, getchar will wait for character.
    int c;
    c = getchar();
    while ((c!='\n') && (c!=EOF)){
        // read until takes the '\n'
        c = getchar();
    }
}