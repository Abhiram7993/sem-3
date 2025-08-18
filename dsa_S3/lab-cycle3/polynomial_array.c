#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

// intializing polynomial
#define MAX 50
typedef struct Poly_node{
	int coeff;
	int expo;
}poly_node;

poly_node P[MAX];

void flush(void);


int main(void){
	int terms;
   printf("Creation\n\n");
   printf("Enter number of terms: ");
   scanf("%i", &terms);
   flush();
   
   int c, e;
   int i=0;
   while (i<terms){
   	printf("Enter coefficient: ");
   	scanf("%i", &c);
   	printf("Enter exponent: ");
   	scanf("%i", &e);
   	
   	P[i].coeff = c;
   	P[i].expo = e;
   	i++;
   }
   
   // displaying terms
   printf("Displaying: ");
   int j=0;
   while (j<terms){
   	printf("%ix^%i + ", P[j].coeff, P[j].expo);
   	j++;
   }
   printf("\n");
   
   // Evaluation
   int x;
   printf("Enter value of x: ");
   scanf("%i", &x);
   flush();
   
   int value = 0;
   int k = 0;
   while (k<terms){
   	value += (P[k].coeff)*pow(x, (P[k].expo));
   	k++;
   }
   
   printf("Evaluated result: %i\n", value);
   return 0;
    
   
}


void flush(void){
	int c = getchar();
	while (c!='\n' && c!=EOF){
		c = getchar();
	}
}












