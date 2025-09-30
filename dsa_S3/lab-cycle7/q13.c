#include <stdio.h>

#define MAX 100

int pq[MAX];
int size = 0;

void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

// Enqueue (insert)
void enqueue(int val) {
    pq[size] = val;
    int i = size++;
    while(i != 0 && pq[i] > pq[(i-1)/2]) {
        swap(&pq[i], &pq[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Dequeue (extract max)
int dequeue() {
    if(size <= 0) return -1;
    int max = pq[0];
    pq[0] = pq[--size];
    int i = 0;
    while(1) {
        int largest = i;
        int l = 2*i+1, r = 2*i+2;
        if(l < size && pq[l] > pq[largest]) largest = l;
        if(r < size && pq[r] > pq[largest]) largest = r;
        if(largest != i) { swap(&pq[i], &pq[largest]); i = largest; }
        else break;
    }
    return max;
}

// Display priority queue
void display() {
    for(int i=0;i<size;i++) printf("%d ", pq[i]);
    printf("\n");
}

int main() {
    enqueue(30); enqueue(20); enqueue(40); enqueue(50); enqueue(10);

    printf("Priority Queue (Max Heap): ");
    display();

    printf("Dequeued (max): %d\n", dequeue());

    printf("Priority Queue after dequeue: ");
    display();

    return 0;
}
