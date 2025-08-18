#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

// intializing polynomial
#define MAX 50
typedef struct node{
	int coeff;
	int expo;
	struct node* next;
}node;

node* polynomial = NULL;;

void flush(void);


int main(void){
	int terms;
   printf("Creation\n\n");
   printf("Enter number of terms: ");
   scanf("%i", &terms);
   flush();
 	
 	int i = 0;
 	while (i<terms){
 		node* newnode = (node*)malloc(sizeof(node));
 		printf("Coefficient: ");
 		scanf("%i", &(newnode->coeff));
 		flush();
 		printf("Exponent: ");
 		scanf("%i", &(newnode->expo));
 		flush();
 		newnode->next = NULL;
 		
 		if (polynomial == NULL){
 			polynomial = newnode;
 		}
 		
 		else{
 			node* traveller = polynomial;
 			while (traveller->next != NULL){
 				traveller = traveller->next;
 			}
 			traveller->next = newnode;
 		}
 		i++;
 	}
 	void flush(void){
	int c = getchar();
	while (c!='\n' && c!=EOF){
		c = getchar();
	}
}
 	int x;
 	printf("Enter value of x: ");
 	scanf("%i", &x);
 	
 	// Evaluating
 	int value = 0;
 	
 	node* traveller = polynomial;
 	while (traveller != NULL){
 		int c = traveller->coeff;
 		int e = traveller->expo;
 		value += (c * (pow(x, e)));
 		traveller = traveller->next;
 	}
 	
 	printf("Resultant: %i\n", value);
 	
 	// freeing memory
 	while(polynomial != NULL){
 		traveller = polynomial;
 		polynomial = polynomial->next;
 		free(traveller);
 	}
 	return 0;
}


void flush(void){
	int c = getchar();
	while (c!='\n' && c!=EOF){
		c = getchar();
	}
}
   
