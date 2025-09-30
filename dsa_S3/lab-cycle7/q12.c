#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

// Insert into max heap
void insert(int val) {
    heap[size] = val;
    int i = size;
    size++;
    while(i != 0 && heap[i] > heap[(i-1)/2]) {
        swap(&heap[i], &heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Delete max (root)
int deleteMax() {
    if(size <= 0) return -1;
    int max = heap[0];
    heap[0] = heap[size-1];
    size--;
    int i = 0;
    while(1) {
        int largest = i;
        int l = 2*i+1, r = 2*i+2;
        if(l < size && heap[l] > heap[largest]) largest = l;
        if(r < size && heap[r] > heap[largest]) largest = r;
        if(largest != i) {
            swap(&heap[i], &heap[largest]);
            i = largest;
        } else break;
    }
    return max;
}

// Display heap
void display() {
    for(int i=0; i<size; i++) printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    insert(30); insert(20); insert(40); insert(15); insert(25); insert(35);

    printf("Max Heap: ");
    display();

    printf("Deleted max: %d\n", deleteMax());

    printf("Heap after deletion: ");
    display();

    return 0;
}
