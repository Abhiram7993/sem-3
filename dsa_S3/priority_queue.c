#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// intializing heap
#define MAX 100
int heap[MAX];
int size = 0;     // stores the number of elements in array.

void insert(int n);
int delete(void);
void peek(void);
void flush(void);


int main(void){
    
    int choice;
 
    printf("\n1 - Insert an element into queue");
    printf("\n2 - Delete an element from queue");
    printf("\n3 - peek queue element");
    printf("\n4 - Exit");
 
    
    while (1)
    {
        printf("\nEnter your choice : ");    
        scanf("%d", &choice);
        flush();
 
        switch (choice)
        {
        case 1:
            int data;
            printf("\nEnter value to be inserted : ");
            scanf("%d",&data);
            flush();
            insert(data);
            break;
        case 2:
            int n;
            n=delete();
            printf("The highest priority elemnt is %d",n);
            break;
        case 3: 
            peek();
            break;
        case 4: 
            exit(0);
        default: 
            printf("\nChoice is incorrect, Enter a correct choice");
        }
    }
    return 1;
}


void insert(int n){
    if (size == 0){
        heap[size] = n;
        size++;
    }
    else if (size == MAX){
        printf("Heap Overflow...\n");
        exit(1);
    }
    else{
        heap[size] = n;
        size++;

        // heafiying up
        int i = size-1;  // new element pointing index
        while ((i > 0) && (heap[i]>heap[(i-1)/2])){
            heap[i] = heap[i] + heap[(i-1)/2];
            heap[(i-1)/2] = heap[i] - heap[(i-1)/2];
            heap[i] = heap[i] - heap[(i-1)/2];

            // reassigning pointer to new element
            i = (i-1)/2;
        }
    }       
}


int delete(void){
    if (size == 0){
        printf("Heap Underflow...\n");
        exit(1);
    }
    // max element is at root
    int data = heap[0];

    // heapifying down
    heap[0] = heap[size-1];
    size--;
    int largest;
    int left;
    int right;
    int i = 0;  // points the curent top parent element.
    // checking condition that it has atleast one child.
    while ((2*i+1)<size){   
        largest = i;
        left = 2*i + 1;
        right = 2*i + 2;

        if (heap[left] > heap[largest]){
            largest = left;
        }
        if ((right < size) && (heap[right] > heap[largest])){
            largest = right;
        }

        // swapping or not
        if (largest == i){
            break;
        }
        else{
            heap[i] = heap[i] + heap[largest];
            heap[largest] = heap[i] - heap[largest];
            heap[i] = heap[i] - heap[largest];

            i = largest;
        }
    }
    return data;
}


void peek(void){
    if (size == 0){
        printf("Heap is empty.\n");
    }
    else{
        printf("%i\n", heap[0]);
    }
}


void flush(void){
    int c = getchar();
    while (c!='\n' && c!=EOF){
        c = getchar();
    }
}