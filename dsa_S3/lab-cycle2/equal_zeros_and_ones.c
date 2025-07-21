#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// initializing a stack for storing 0s
char STACK[100];
int top = -1;

void evaluate(char* sequence);
void pop(void);
void push(char c);
void evaluate(char* sequence);


int main(void){
	char sequence[100];
	printf("Enter sequence: ");
	
	// reading string and saving to epression
	if (fgets(sequence, 100*sizeof(char), stdin)){
		sequence[strcspn(sequence, "\n")] = '\0';
	}
	
	evaluate(sequence);
	return 0;
}


void evaluate(char* sequence){
	
	int ones = 0;
	
	for (int i=0; sequence[i]!='\0'; i++){
		
		char symbol = sequence[i];
		
		if (symbol == '0'){
			push(symbol);
		}
		
		else if (symbol == '1'){
			ones ++;
			continue;
		}
		
		else{
			printf("Invalid character in sequence.\n");
			exit(1);
		}	
	}
	
	for (int j=0; j<ones; j++){
		pop();
	}
	
	if (top == -1){
		printf("Sequence contains equal 0s and 1s.\n");
	}
	else{
		printf("Sequence contains unequal 0s and 1s.\n");
	}
}


void push(char c){
	if (top == 99){
		printf("Stack Overflow.\n");
		exit(1);
	}
	top++;
	STACK[top] = c;
}


void pop(void){
	if (top == -1){
		printf("Stack Underflow\n");
		exit(1);
	}
	top--;
}























