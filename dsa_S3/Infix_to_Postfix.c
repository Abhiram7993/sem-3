#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // For isalnum

// --- Constants and Type Definitions ---

// Define Associativity
typedef enum {
    ASSOC_LEFT,
    ASSOC_RIGHT
} Associativity;

// Define Operator structure
typedef struct {
    char symbol;
    int precedence;
    Associativity assoc;
} Operator;

// Operator properties lookup table
const Operator OPERATORS[] = {
    {'+', 1, ASSOC_LEFT},
    {'-', 1, ASSOC_LEFT},
    {'*', 2, ASSOC_LEFT},
    {'/', 2, ASSOC_LEFT},
    {'^', 3, ASSOC_RIGHT} // Exponentiation is right-associative
};
const int NUM_OPERATORS = sizeof(OPERATORS) / sizeof(OPERATORS[0]);

// --- Stack Implementation (for operators) ---

#define MAX_EXPRESSION_LENGTH 100 // Adjust as needed
char operator_stack[MAX_EXPRESSION_LENGTH];
int top = -1; // Stack top index

void push(char op) {
    if (top >= MAX_EXPRESSION_LENGTH - 1) {
        fprintf(stderr, "Error: Operator stack overflow!\n");
        exit(EXIT_FAILURE);
    }
    operator_stack[++top] = op;
}

char pop() {
    if (top == -1) {
        fprintf(stderr, "Error: Operator stack underflow!\n");
        exit(EXIT_FAILURE);
    }
    return operator_stack[top--];
}

char peek() {
    if (top == -1) {
        return '\0'; // Null character to signify empty stack
    }
    return operator_stack[top];
}

int is_stack_empty() {
    return top == -1;
}

// --- Helper Functions for Operator Properties ---

// Returns a pointer to the Operator struct, or NULL if not found
const Operator* get_operator_info(char symbol) {
    for (int i = 0; i < NUM_OPERATORS; i++) {
        if (OPERATORS[i].symbol == symbol) {
            return &OPERATORS[i];
        }
    }
    return NULL; // Not a defined operator
}

int is_operand(char c) {
    return isalnum(c);
}

// --- Main Infix to Postfix Conversion Algorithm ---

void infix_to_postfix(const char *infix_expression) {
    // Postfix can be longer than infix (e.g., A+B -> AB+, 3 chars to 4 chars)
    // A safe size is 2 * MAX_EXPRESSION_LENGTH + 1 for null terminator
    char postfix_expression[MAX_EXPRESSION_LENGTH * 2 + 1];
    int postfix_idx = 0;

    // Reset stack for each conversion
    top = -1;
    postfix_idx = 0;

    for (int i = 0; infix_expression[i] != '\0'; i++) {
        char symbol = infix_expression[i];
        if (isspace(symbol)) { // Skip whitespace
            continue;
        }

        if (is_operand(symbol)) {
            postfix_expression[postfix_idx++] = symbol;
        } else if (symbol == '(') {
            push(symbol);
        } else if (symbol == ')') {
            while (!is_stack_empty() && peek() != '(') {
                postfix_expression[postfix_idx++] = pop();
            }
            if (is_stack_empty()) {
                fprintf(stderr, "Error: Mismatched parentheses (missing opening parenthesis) in '%s'.\n", infix_expression);
                exit(EXIT_FAILURE);
            }
            pop(); // Pop and discard '('
        } else { // It's an operator
            const Operator* o1_info = get_operator_info(symbol);
            if (o1_info == NULL) {
                fprintf(stderr, "Error: Invalid symbol '%c' encountered in '%s'.\n", symbol, infix_expression);
                exit(EXIT_FAILURE);
            }

            while (!is_stack_empty() && peek() != '(') {
                char o2_symbol = peek();
                const Operator* o2_info = get_operator_info(o2_symbol);

                if (o2_info == NULL) { // Should not happen if parsing valid operators
                    fprintf(stderr, "Error: Unknown operator '%c' on stack. This indicates an internal error.\n", o2_symbol);
                    exit(EXIT_FAILURE);
                }

                // Condition for Popping o2
                if ((o2_info->precedence > o1_info->precedence) ||
                    (o2_info->precedence == o1_info->precedence && o1_info->assoc == ASSOC_LEFT)) {
                    postfix_expression[postfix_idx++] = pop();
                } else {
                    break; // Break the while loop
                }
            }
            push(symbol);
        }
    }

    // After scanning the entire expression
    while (!is_stack_empty()) {
        char popped_op = pop();
        if (popped_op == '(') {
            fprintf(stderr, "Error: Mismatched parentheses (missing closing parenthesis) in '%s'.\n", infix_expression);
            exit(EXIT_FAILURE);
        }
        postfix_expression[postfix_idx++] = popped_op;
    }
    postfix_expression[postfix_idx] = '\0'; // Null-terminate final postfix string

    printf("Infix:  %s\n", infix_expression);
    printf("Postfix: %s\n", postfix_expression);
}

// --- Main function to run tests ---
int main(void) {
    // Test cases
    const char *test_expressions[] = {
        "A + B * C",
        "A - B + C",
        "A ^ B ^ C",
        "(A + B) * C",
        "A + (B - C) * D",
        "(A ^ B - C * D) / E + F ^ G ^ H", // Complex Question 1
        "X - Y ^ Z ^ 2 / (P + Q) * R",      // Complex Question 2
        NULL // Sentinel to mark end of array
    };

    for (int i = 0; test_expressions[i] != NULL; i++) {
        infix_to_postfix(test_expressions[i]);
        printf("\n"); // Add a newline for separation between test cases
    }

    return 0;
}