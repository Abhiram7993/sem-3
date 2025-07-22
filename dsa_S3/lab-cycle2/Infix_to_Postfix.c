#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // This header file contains isalnum()
#include <string.h>

// Lets define a datatype associvity for operators associvity. 
// We 'dont need' to add name of datatype along with enum
typedef enum {
    ASSOC_LEFT, ASSOC_RIGHT
}Associvity;

// Lets define a datastructure for saving an operator
// We 'need' to add name of datastructure along with struct
typedef struct OPERATOR{
    char symbol;
    int precedence;
    Associvity assoc;
}OPERATOR;

// Lets define an array of total operators
OPERATOR OPERATORS[] = {
    {'^', 3, ASSOC_RIGHT}, 
    {'*', 2, ASSOC_LEFT}, 
    {'/', 2, ASSOC_LEFT}, 
    {'+', 1, ASSOC_LEFT}, 
    {'-', 1, ASSOC_LEFT}
};

// a constant for saving number of OPERATORS
const int NUM_OPERATORS = 5;

// Creating a stack for saving operators
#define OPERATORS_LENGTH 100
char OPERATOR_STACK[OPERATORS_LENGTH];
// pointer for pointing top of stack, this will point on latest data of stack
int top = -1;

void postfix_of(char* infix_expression);
void push(char operator);
char pop(void);
char peak(void);
int isstackempty(void);
OPERATOR* getinfo(char op);


int main(void){

    char expression[200];
    printf("Enter the infix expression: ");
    // reading the expression. Note that fgets also read \n
    if (fgets(expression, sizeof(expression), stdin)){
        expression[strcspn(expression, "\n")] = '\0';
    }
    // evaluating and finding postfix of that expression
    postfix_of(expression);
    return 0;
}


// Lets define postfix_of() function, this fn will print the postfix of the
// infix expression passing, so the return type is void
void postfix_of(char* infix_expression){

    // Lets define an array for storing postfix expression
    char postfix_expression[200];
    // Lets define a variable which points the memory which is to be filled.
    int index = 0;

    // iterating to each character of expression
    for (int i=0; infix_expression[i] != '\0'; i++){
        char character = infix_expression[i];

        // Lets verify that the iterated character is not a space. If space then dont do below verifications and continue iteration from next step.
        if (isspace(character)){
            continue;  
        }

        // Lets check that is it an operand or not, If operand then we can directly add to postfix
        // isalnum only return 1 for alphabets and integers. For all other chars including '\0', it returns 0
        if (isalnum(character)){
            postfix_expression[index] = character;
            index ++;
            continue;
        }

        // if the character is left paranthesis. then we can push it to operator stack
        if (character == '('){
            push(character);
            continue;
        }

        // If the character is right paranthesis
        else if (character == ')'){
            while (!isstackempty() && peak()!='('){
                postfix_expression[index] = pop();
                index ++;
            }

            // if the loop is break due to empty stack, then it means expression has missing left paranthesis.
            if (isstackempty()){
                printf("Expression is invalid (missing a left paranthesis).\n");
                exit(1);
            }

            // if program not exited, it means loop is breaked due'(', so lets pop it
            pop();
            continue; 
        }

        // If the character is operator, let the readed operator as o1.
        // We need info about that operator and we need to confirm that o1 is a valid operator.
        // lets define o1_info which stores the address of operator in 'OPERATORS', get_info() will return that address.
        // If the operator DNE, then get_info() will return NULL
        else{
            OPERATOR* o1_info = getinfo(character);
            // if not a valid operator
            if (o1_info == NULL){
                printf("Your expression contains invalid operator '%c'\n", character);
                printf("Expression cant be evaluated.\n");
                exit(1);
            }

            // So the operator is a valid operator. Now lets check the condition for popping existing opeartors.
            while (!isstackempty() && (peak() != '(')){

                // let o2 be the operator at top
                OPERATOR* o2_info = getinfo(peak());
                // It will be a valid operator bcuz we pushed it into stack

                // Lets check the condition for popping existing data.
                if ((o1_info->precedence < o2_info->precedence) || 
                   ((o1_info->precedence == o2_info->precedence) && (o1_info->assoc == ASSOC_LEFT))){

                    postfix_expression[index] = pop();
                    index ++;
                    continue;
                }

                // condition for poping is not satisfied, it means the 01 can be pushed. So lets break the loop
                else{
                    break;
                }
            }
            push(character);
        }
    }
    // Now the running of for loop completed and all characters are readed.
    // Remaining element in stack is adding to expression.
    while (!isstackempty() && (peak() != '(')){
        postfix_expression[index] = pop();
        index ++;
    }

    // We cant use peak() here, if stack is empty peak() will return garbage values
    if (!isstackempty()){
        printf("Expression cant evaluated ( Unclosed '(' is encountered ).\n");
        exit(1);
    }

    // Lets complete close the string postfix expression and print it
    postfix_expression[index] = '\0';
    printf("Infix expression: %s\n", infix_expression);
    printf("Postfix expression: %s\n", postfix_expression);
}


void push(char operator){
    if (top == OPERATORS_LENGTH){
        printf("Stack Overflow...\n");
        exit(1);
    }
    top++;
    OPERATOR_STACK[top] = operator;
}


char pop(void){
    if (top == -1){
        printf("Stack Underflow...\n");
        exit(1);
    }
    char c = OPERATOR_STACK[top];
    top--;
    return c;
}


char peak(void){
    if (top == -1){
        return '\0';
    }
    return OPERATOR_STACK[top];
}


int isstackempty(void){
    return (top == -1);
}


// This fn will return the address of operator in OPERATORS
OPERATOR* getinfo(char op){
    for (int i=0; i<NUM_OPERATORS; i++){
        if (OPERATORS[i].symbol == op){
            return &OPERATORS[i];
        }
    }
    return NULL;
}