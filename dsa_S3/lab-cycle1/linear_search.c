#include <stdio.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>

int array[100];
int len;

void flush(void);
void linear_search(int n);


int main(void){
    clock_t start, end;
    double time_consumed;
    int search;

    printf("Enter number of elements: ");
	scanf("%i", &len);
	flush();

	for (int i=0; i<len; i++){
		printf("Enter number: ");
		scanf("%i", &array[i]);
		flush();
	}

    printf("Element to search: ");
    scanf("%i", &search);
    flush();

    // starting time measurement
    start = clock();

    linear_search(search);

    // stopping time measurement
    end = clock();

    // time calculation and converting to seconds
    time_consumed = ((double)(end - start))/CLOCKS_PER_SEC;

    printf("Linear searching consumed %f seconds.\n", time_consumed);

    return 0;
}


void flush(void){
	int c = getchar();
	while (c!='\n' && c!=EOF){
		c = getchar();
	}
}


void linear_search(int n){
    for (int i=0; i<len; i++){
        if (n == array[i]){
            printf("Element find at index %i\n", i);
            return;
        }
    }
    printf("Element not found in array.\n");
}