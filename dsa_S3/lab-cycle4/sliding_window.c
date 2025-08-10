#include <stdio.h>
#include <stdlib.h>

// array for saving elements
#define MAX 100
int array[MAX];
int size;

// Queue for saving max element in each windows
int QUEUE[MAX];
int front = -1;
int rear = -1;

void flush(void);
void sliding_window(int k);
int sizeofQ(void);
int Dequeue(void);
void Enqueue(int n);


int main(void){

    // setting up array
    printf("Enter number of elements in array: ");
    scanf("%i", &size);
    flush();
    if (!(size>0)){
        printf("Invalid input.\n");
        exit(1);
    }
    int i=0;
    while (i<size){
        printf("Enter data: ");
        scanf("%i", &(array[i]));
        flush();
        i++;
    }

    int k;
    printf("Size of window: ");
    scanf("%i", &k);
    flush();
    sliding_window(k);

    int n = sizeofQ();
    printf("maximum elements of the sliding windows are: \n");
    for (int j=0; j<n; j++){
        printf("%i\t ", Dequeue());
    }
    printf("\n");

    return 0;
}


void sliding_window(int k){
    for (int i=0; i<(size-k+1); i++){
        int max;
        int flag = 0;
        for (int j=i; j<(i+k); j++){
            if (!flag){
                max = array[j];
                flag = 1;
            }
            else{
                if (array[j] > max){
                    max = array[j];
                }
            }
        }
        Enqueue(max);
    }
}


void flush(void){
    int c = getchar();
    while (c!='\n' && c!=EOF){
        c = getchar();
    }
}


int sizeofQ(void){
    return (rear-front+1);
}


void Enqueue(int n){
    if (rear == MAX-1){
        printf("stack Overflow.\n");
        exit(1);
    }
    rear++;
    QUEUE[rear] = n;

    if (front == -1){
        front++;
    }
}


int Dequeue(void){
    if (front == -1){
        printf("Stack Underflow.\n");
        exit(1);
    }
    int data = QUEUE[front];
    if (front == rear){
        front = rear = -1;
    }
    else{
        front++;
    }
    return data;
}