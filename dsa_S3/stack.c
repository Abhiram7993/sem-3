#include <stdio.h>
#include <stdlib.h>

#define MAX 5

void push(int* stack, int* PointerTop);
void pop(int* stack, int* PointerTop);
void display(int* stack, int* PointerTop);


/*While incrementing values inside a pointer always use bracket
*PointerTop++ it will increment the address no the value
(*PointerTop)++ it will increment the value inside the location. This is due to order preference.*/
int main(void){

    int stack[MAX];
    int top = -1;

    while (1){

        int option;
        printf("Menu\n1.Push\n2.Pop\n3.Display\n4.Exit\nChoice: ");
        scanf("%d", &option);

        switch (option){
            case 1:
                push(stack, &top);
                break;
            case 2:
                pop(stack, &top);
                break;
            case 3:
                display(stack, &top);
                break;
            case 4:
                exit(0);
            default:
                printf("Enter valid input\n\n");
            
        }
    }
}


void push(int* stack, int* PointerTop){

    if (*PointerTop == MAX-1){
        printf("Stack is full.\n\n");
    }
    else{
        int data;
        printf("Data: ");
        scanf("%d", &data);
        printf("\n");

        // Using bracket while incrementing.
        (*PointerTop)++; 
        stack[*PointerTop] = data;
    }
}


void pop(int* stack, int* PointerTop){

    if (*PointerTop == -1){
        printf("All values are already popped.\n\n");
    }
    else{
        printf("%i\n", stack[*PointerTop]);
        (*PointerTop)--;
        printf("\n");
    }
}


void display(int* stack, int* PointerTop){

    for (int i=0; i<= *PointerTop; i++){
        printf("%i\n", stack[(*PointerTop) - i]);
    }
    printf("\n");

}