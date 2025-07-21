#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// initializing a stack
int MAIN_STACK[100];
int main_top = -1;

// initializing an auxilary stack
int AUX_STACK[100];
int aux_top = -1;

void push(void);
int pop(void);
void flush(void);
void find(void);


int main(void){

    while (1){

        int option;
        printf("Menu\n1.Push\n2.Pop\n3.Find\n4.Exit\nChoice: ");
        scanf("%d", &option);
        flush();

        switch (option){
            case 1:
                push();
                break;
            case 2:
                printf("%i\n", pop());
                break;
            case 3:
                find();
                break;
            case 4:
                exit(0);
            default:
                printf("Enter valid input\n\n");
            
        }
    }
    return 1;
}


void push(void){
	if (main_top == 99){
		printf("Stack Overflow");
		exit(1);
	}
	int data;
	printf("Enter data: ");
	scanf("%i", &data);
	flush();
	
	main_top++;
	MAIN_STACK[main_top] = data;
}


int pop(void){
	if (main_top == -1){
		printf("Stack Underflow");
		exit(1);
	}
	int data = MAIN_STACK[main_top];
	main_top--;
	return data;
}


void flush(void){
	int c = getchar();
	while ((c != '\n') && (c != EOF)){
		c = getchar();
	}
}


// this function will return within how pop() you will get that data
void find(void){
	if (main_top == -1){
		printf("Stack is free\n");
		return;
	}
	int data;
	int FLAG = 0;
	printf("Enter data to find: ");
	scanf("%i", &data);
	flush();
	int num_of_pop = 0;
	
	// popping elements from stack and sdding to auxillary stack until data is found
	while (main_top != -1){
		int n = pop();
		num_of_pop++;
		
		aux_top++;
		AUX_STACK[aux_top] = n;
		
		if (n == data){
			FLAG = 1; 
			break;
		}
	}
	if (FLAG)
		printf("Your element will be found at %ith pop\n", num_of_pop);
	else
		printf("Your data is not present in stack\n");	
	
	// reassinging elements to stack
	while (aux_top != -1){
		int num = AUX_STACK[aux_top];
		aux_top--;
		
		main_top++;
		MAIN_STACK[main_top] = num;
	}
}
		
		
	
	
	






























