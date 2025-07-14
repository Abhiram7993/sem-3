#include <stdio.h>
#include <stdlib.h>

#define NUMBER 38


int main(void){

    int stack[50];
    int top = -1;

    // finding binary of NUMBER
    int n = NUMBER;

    if (n == 0){
        top++;
        stack[top] = 0;
    }

    while (n > 0){ 
        top++;
        stack[top] = n%2;
        n/=2;
    }

    // printing the contents of the stack.
    // Note that top points the top element ie, it stores the index of top element.
    // It does not stores the number of elements.
    for (int i=0; i<=top; i++){
        printf("%i", stack[top-i]);
    }
    printf("\n");

    return 0;
}