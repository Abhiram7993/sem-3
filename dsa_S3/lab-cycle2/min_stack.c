#include <stdio.h>
#include <stdlib.h>

#define MAX 5

void push(int* stack, int* PointerTop);
void pop(int* stack, int* PointerTop);
void peek();
void flush();

// auxilary stack
int Minstack[MAX];
int min = -1;


/*While incrementing values inside a pointer always use bracket
*PointerTop++ it will increment the address no the value
(*PointerTop)++ it will increment the value inside the location. This is due to order preference.*/
int main(void){

    int stack[MAX];
    int top = -1;

    while (1){

        int option;
        printf("Menu\n1.Push\n2.Pop\n3.Minimum Element\n4.Exit\nChoice: ");
        scanf("%d", &option);
        flush();

        switch (option){
            case 1:
                push(stack, &top);
                break;
            case 2:
                pop(stack, &top);
                break;
            case 3:
                peek();
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
        flush();
        printf("\n");

        // Using bracket while incrementing.
        (*PointerTop)++; 
        stack[*PointerTop] = data;
        
        // Adding minimal element.
    	  if (min == -1){
            Minstack[0] = data;
            min++;
        }
        else{
    	      if (data < Minstack[min]){
    	          min++;
    	          Minstack[min] = data;
    	      }
        }
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


void peek(){
	 if (min == -1){
	     printf("First add some number\n\n");
	     return;
	 }
    printf("%i\n", Minstack[min]);
    printf("\n");

}

void flush(){
	int c;
	c = getchar();
	while ((c != '\n')&&(c != EOF)){
		c = getchar();
	}
}

