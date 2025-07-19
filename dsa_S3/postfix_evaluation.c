// Here I will assume that the numbers are single digits

#include <stdio.h>
#include <stdlib.h>  // atoi() lives here
#include <string.h>
#include <ctype.h>
#include <math.h>

// stack for saving operands
#define STACK_LEN 100
int STACK_NUM[STACK_LEN];
int top = -1;

int value_of(char* postfix);
int operation(char c);
void push(int n);
int pop(void);


int main(void){
    char expression[100];

    printf("Enter postfix expression: ");
    if (fgets(expression, 100*sizeof(char), stdin)){
        expression[strcspn(expression, "\n")] = '\0'; 
    }

    int value = value_of(expression);
    printf("Value of the given postfix expression is %i.\n", value);
    
    return 0;
}


int value_of(char* postfix){

    for (int i=0; i<strlen(postfix); i++){
        char character = postfix[i];

        // check whether is it space
        if (isspace(character)){
            continue;
        }

        // if its a number
        else if (isdigit(character)){
            int n = character - '0';     // ascii value of remaining character is int(character)
            push(n);
        }

        // if its a symbol
        else{
            int value = operation(character);
            push(value);
        }
    }

    if (top != 0){
        printf("Expression is invalid.\n");
        exit(1);
    }

    return pop();
}


int operation(char c){
    if (top < 1){
        printf("Operation cant be evaluated (Insufficient operands).\n");
        exit(1);
    }
    int op2 = pop();
    int op1 = pop();

    switch (c){
        case '+':
            return (op1 + op2);
        case '-':
            return (op1 - op2);
        case '*':
            return (op1 * op2);
        case '/':
            if (op2 == 0){
                printf("Expression cant evaluated (Zero division error).\n");
                exit(1);
            }
            return (op1 / op2);
        case '^':
            return pow(op1, op2);
        default:
            printf("Expression cant be evaluated (Invalid operator).\n");
            exit(1);
    }
}


void push(int n){
    if (top >= STACK_LEN-1){
        printf("Stack Overflow.\n");
        exit(1);
    }
    top ++;
    STACK_NUM[top] = n;
}

int pop(void){
    if (top < 0){
        printf("Stack Underflow.\n");
        exit(1);
    }
    int data = STACK_NUM[top];
    top --;
    return data;
}