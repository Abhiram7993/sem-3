// Here the numbers can be one or more digits. But each number is seperated by space
#include <stdio.h>
#include <math.h>
#include <ctype.h> // for isspace, isdigit...
#include <stdlib.h> // atoi
#include <string.h>

// Stack for storing operands
#define STACK_LEN 100
int STACK_NUM[STACK_LEN];
int top = -1;

int value_of(char* postfix_expression);
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


int value_of(char* postfix_expression){

    int i = 0;
    while (i<strlen(postfix_expression)){
        char character = postfix_expression[i];

        // If space then ignore it
        if (isspace(character)){
            i++;
            continue;
        }

        // If its operand 
        else if (isdigit(character)){
            char num[10];
            int n = 0;
            while (!isspace(postfix_expression[i])){
                num[n] = postfix_expression[i];
                n++;
                i++;
            }
            i++;
            num[n] = '\0';
            int number = atoi(num);
            push(number);
            continue;
        }

        // Its operator
        else{
            int value = operation(character);
            push(value);
            i++;
        }
    }

    // After evaluating all the expression, the stack will contains only one character.
    // That will be the result
    if (top != 0){
        printf("Invalid Expression (Operands remaining in stack).\n");
        exit(1);
    }

    return pop();
}


int operation(char c){
    if (top < 1){
        printf("Invalid Expression (less number of operands for operation).\n");
        exit(1);
    }
    int op2 = pop();
    int op1 = pop();

    switch (c){
        case '+':
            return (op1 + op2);
        case '-':
            return (op1 - op2);
        case '/':
            if (op2 == 0){
                printf("Invalid Expression (Zero division error).\n");
                exit(1);
            }
            return (op1/op2);
        case '*':
            return (op1 * op2);
        case '^':
            return pow(op1, op2);
        default:
            printf("Invalid Expression (Operand is unknown).\n");
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
    top--;
    return data;
}