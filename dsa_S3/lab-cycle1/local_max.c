#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int NUMBERS[100];
int num_len = 0; // for saving elements already on array

void Local_Max(void);
void flush(void);


int main(void){
    int n; // for saving no. of elements adding to array
    printf("Number of elements: ");
    scanf("%i", &n);
    flush();

    // In array we need only unique elements
    int temp;

    while (num_len<n){
        printf("Enter a number: ");
        scanf("%i", &temp);
        flush();

        // checking whether element already in array or not
        int flag = 1;  // If not exist then 1 else 0.
        if (num_len > 0){
            for (int i=0; i<num_len; i++){
                if (temp == NUMBERS[i]){
                    flag = 0;
                }
            }
        }
        if (flag){
            NUMBERS[num_len] = temp;
            num_len++;
        }
        else{
            printf("Element already exist. Enter a unique one.\n");
        }
    }

    Local_Max();
    return 0;
}

void flush(void){
    int c = getchar();
    while (c!='\n' && c!=EOF){
        c = getchar();
    }
}


void Local_Max(void){
    printf("Local Maximas: ");
    for (int i=1; i<num_len; i++){
        if (NUMBERS[i] > NUMBERS[i-1]){
            printf("%i, ", NUMBERS[i]);
        }
    }
    printf("\n");
}