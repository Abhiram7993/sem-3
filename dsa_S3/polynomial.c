#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int coefficient;
    int exponent;
} polynomial;


void addPolynomial(polynomial* p1, int n1, polynomial* p2, int n2, polynomial* result, int* nR);
void printPolynomial(polynomial* result, int n);


int main(void){

    polynomial p1[10] = {{5,3}, {4,2}, {7,1}};
    int n1 = 3;
    polynomial p2[10] = {{5,2}, {5,1}, {5,0}};
    int n2 = 3;
    polynomial result[10];
    int nR;

    addPolynomial(p1, n1, p2, n2, result, &nR);
    printPolynomial(result, nR);

    return 0;
}


void addPolynomial(polynomial* p1, int n1, polynomial* p2, int n2, polynomial* result, int* nR){
    
    int i=0, j=0, k=0;
    while (i<n1 && j<n2){

        if (p1[i].exponent == p2[j].exponent){
            result[k].exponent = p1[i].exponent;
            result[k].coefficient = p1[i].coefficient + p2[j].coefficient;
            i++;
            j++;
            k++;
        }

        else if (p1[i].exponent > p2[j].exponent){
            result[k] = p1[i];
            k++;
            i++;
        }

        else {
            result[k] = p2[j];
            k++;
            j++;
        }
    }

    while (i < n1){
        result[k] = p1[i];
        i++;
        k++;
    }

    while (j < n2){
        result[k] = p2[j];
        j++;
        k++;
    }

    *nR = k;
}

void printPolynomial(polynomial* result, int n){
    
    for (int i=0; i<n; i++){
        printf("(%i, %i)\n", result[i].coefficient, result[i].exponent);
    }
}