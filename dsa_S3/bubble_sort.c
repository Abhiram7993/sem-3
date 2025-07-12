#include <stdio.h>
#include <time.h>

void bubble_sort(int* a, int n);
void print_array(int* a, int n);

int main(){

    // aim of this program is to compute the time taken for bubble sorting.
    int array[] = {56, 78, 34, 15, 59, 82};
    int n = 6;
    // To decline variables which measure time we need to use 'clock_t' variable
    clock_t start, end;
    // To calculate time in seconds we can use this 'double' variable
    double time_taken;

    // Lets collect starting time
    start = clock();
    
    // Calling bubble sort.
    bubble_sort(array, n);

    // Lets collect time in which bubble sort stops.
    end = clock();

    // Lets calculate time taken, Here 'CLOCKS_PER_SEC' is used to, 
    // convert the number returned by clock() function to seconds
    time_taken = ((double)(end - start))/CLOCKS_PER_SEC;

    printf("time taken for bubble_sort is %f\n", time_taken);
    print_array(array, n);

    return 0;
}


void bubble_sort(int* a, int n){
    
    for (int i=0; i<n-1; i++){
        int flag = 0;
        for (int j=0; j<n-1-i; j++){
             if (a[j] > a[j+1]){
                a[j] = a[j] + a[j+1];
                a[j+1] = a[j] - a[j+1];
                a[j] = a[j] - a[j+1];
                flag = 1;
             }
        }
        if (flag == 0){
            break;
        }
    }
}


void print_array(int* a, int n){

    for (int i=0; i<n; i++){
        printf("%i\t", a[i]);
    }
    printf("\n");
}


// Now we know how to use time.h to find the time for an operation.