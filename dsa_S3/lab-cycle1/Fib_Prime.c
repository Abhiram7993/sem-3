#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool issprime(int n);
void fib(void);
void flush(void);


int main(void){
    while (1){
        int n;
        printf("menu\n");
        printf("1. Fibonacci Series less than 100\n2. Prime Numbers less than 100\n3.exit\n");
        printf("Choice: ");
        scanf("%i", &n);
        flush();

        switch (n){
            case 1:
                fib();
                break;

            case 2:
                for (int i=1; i<=100; i++){
                    if (issprime(i)){
                        printf("%i, ", i);
                    }
                }
                printf("\n\n");
                break;
            
            case 3:
                exit(0);
                break;

            default:
                printf("Enter a valid number.\n");
        }
    }
    return 1;  
}


// This fn will return the nth fibonacci term
void fib(void){
    int series[100];
    int len = 0;

    // initial cases
    series[len] = 0;
    len++;

    series[len] = 1;
    len++;

    while (1){
        int temp = series[len-1] + series[len-2];
        if (temp > 100){
            break;
        }
        series[len] = temp;
        len++;
        
    }

    // printing sequence
    for (int i=0; i<len; i++){
        printf("%i, ", series[i]);
    }
    printf("\n\n");
}


// This fn will check is it prime or not
bool issprime(int n){
    if (n == 1){
        return false;
    }

    bool flag = true;
    for (int i=2; i<n; i++){
        if (n%i == 0){
            flag = false;
        }
    }
    return flag;
}


void flush(void){
    int c = getchar();
    while (c!='\n' && c!=EOF){
        c = getchar();
    }
}
