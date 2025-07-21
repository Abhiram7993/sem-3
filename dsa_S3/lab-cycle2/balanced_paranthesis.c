#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// initializing a stack for storing paranthesis
char STACK[100];
int top = -1;

void evaluate(char* expression);
void push(char c);
void pop(void);


int main(void){
	char expression[100];
	printf("Enter an expression: ");
	
	// reading string and saving to epression
	if (fgets(expression, 100*sizeof(char), stdin)){
		expression[strcspn(expression, "\n")] = '\0';
		}
		
	evaluate(expression);
	return 0;
}


void evaluate(char* expression){
	
	// iterating to the expression
	for (int i=0; expression[i]!='\0'; i++){
	
		char symbol = expression[i];
		
		if ((symbol == '(')|(symbol == '[')|(symbol == '{')){
			push(symbol);
			continue;
		}
		else if ((symbol == ')')|(symbol == ']')|(symbol == '}')){
			pop();
		}
		else{
			continue;
			}
	}
	
	if (top == -1){
		printf("Expression has correct paranthesis.\n");
	}
	else{
		printf("Expression is invalid.\n");
		exit(1);
	}
}


void push(char c){
	if (top == 99){
		printf("Stack Overflow\n");
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
	





















