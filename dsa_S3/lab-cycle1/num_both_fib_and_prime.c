#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool issprime(int n);
void flush(void);


int main(void){

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

    // series contains fib sequence
    printf("Numbers which are both prime and in fib sequence are: \n");
    for (int i=0; i<len; i++){
        if (issprime(series[i])){
            printf("%i, ", series[i]);
        }
    }
    printf("\n");
    return 0;
}


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
