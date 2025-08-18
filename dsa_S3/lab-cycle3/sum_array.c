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

poly_node P1[MAX];
int p1 = 0;
poly_node P2[MAX];
int p2 = 0;
poly_node P3[MAX];
int p3 = 0;

void flush(void);
void create_polynomial(poly_node* P, int* p);
void add(void);
void display(poly_node* P, int* p);


int main(void){
   // creating polynomials
   create_polynomial(P1, &p1);
   create_polynomial(P2, &p2);
   
  	// Adding polynomials
  	add(); 
   
   // displaying terms
   display(P1, &p1);
   display(P2, &p2);
   display(P3, &p3);
   
   return 0;
}


void flush(void){
	int c = getchar();
	while (c!='\n' && c!=EOF){
		c = getchar();
	}
}


void create_polynomial(poly_node* P, int* p){
	int terms;
   printf("Enter number of terms: ");
   scanf("%i", &terms);
   flush();
   
	int c, e;
	*p = terms;
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
}


void add(void){
	int i=0, j=0, k=0;
	
	while (i<p1 && j<p2){
		if (P1[i].expo > P2[j].expo){
			P3[k] = P1[i];
			i++;
			k++;
		}
		else if (P1[i].expo < P2[j].expo){
			P3[k] = P2[j];
			k++;
			j++;
		}
		else{
			P3[k].coeff = P1[i].coeff + P2[j].coeff;
			P3[k].expo = P1[i].expo;
			i++;
			j++;
			k++;
		}
	}
	
	while (i<p1){
		P3[k] = P1[i];
		k++;
		i++;
	}
	
	while (j<p2){
		P3[k] = P2[j];
		k++;
		j++;
	}
	
	p3 = k;
}


void display(poly_node* P, int* p){
	int j=0;
   while (j<(*p)){
   	printf("%ix^%i + ", P[j].coeff, P[j].expo);
   	j++;
   }
   printf("\n");
}


































