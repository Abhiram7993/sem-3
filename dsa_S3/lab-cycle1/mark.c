#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int MARKS[100];
int mark_len;

void flush(void);
void bubble_sort(void);
void insert(void);
void display(void);


int main(void){

    printf("Total no. of students: ");
    scanf("%i", &mark_len);
    flush();
    
    for (int i=0; i<mark_len; i++){
        printf("Enter number: ");
        scanf("%i", &MARKS[i]);
        flush();
    }
    bubble_sort();

    int n;
    while (1){
        printf("\n1. Insert\n2. Display\n3. Exit\n");
        printf("Select an option: ");
        scanf("%i", &n);
        flush();

        switch (n){
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                printf("exiting program...\n");
                exit(0);
                break;
            default:
                printf("Enter a valid option.\n");
        }
    }
    return 1;
}


void flush(void){
    int c = getchar();
    while (c!='\n' && c!=EOF){
        c = getchar();
    }
}


void bubble_sort(void){
    for (int i=0; i<mark_len-1; i++){
        int flag = 1;
        for (int j=0; j<mark_len-1-i; j++){
            if (MARKS[j] < MARKS[j+1]){
                MARKS[j] = MARKS[j] + MARKS[j+1];
                MARKS[j+1] = MARKS[j] - MARKS[j+1];
                MARKS[j] = MARKS[j] - MARKS[j+1];
                flag = 0;
            }
        }
        if (flag){
            break;
        }
    }
}


void insert(void){
    int data;
    printf("Enter a number: ");
    scanf("%i", &data);
    flush();
    int flag = 1;

    for (int i=0; i<mark_len; i++){
        if (MARKS[i] < data){
            flag = 0;
            // till element at index i-1 or ith number is at correct order
            // So total elements we need to replace is mark_len-i
            for (int j=0; j<mark_len-i; j++){
                MARKS[mark_len-j] = MARKS[mark_len-1-j];
            }
            MARKS[i] = data;
            mark_len++;
            break;
        }
    }
    if (flag){
        MARKS[mark_len] = data;
        mark_len++;
    }
}


void display(void){
    for (int i=0; i<mark_len; i++){
        printf("%i\t", MARKS[i]);
    }
    printf("\n");
}