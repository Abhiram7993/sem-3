#include <stdio.h>
#include <time.h>

void bubble_sort(int* array, int n);
void print_array(int* array, int n);

int main(){

	int array[] = {89, 34, 26, 90, 68, 55, 10, 100, 74};
	int n = 9;
	clock_t start, end;
	double cpu_time_used;
	
	// starting time calculation.
	start = clock();
	
	bubble_sort(array, n);
	
	// ending time calculation.
	end = clock();
	
	print_array(array, n);
	printf("\n");
	
	// Calculating the time taken for bubble sort
	cpu_time_used = ((double)(end - start))/CLOCKS_PER_SEC;
	printf("Time taken for bubble sorting is %f seconds\n", cpu_time_used);
	
	return 0;
}


void bubble_sort(int* array, int n){

	for (int i=0; i<n-1; i++){
	
		int flag = 0;
		
		for (int j=0; j<n-i-1; j++){
			if (array[j] > array[j+1]){
				array[j] = array[j] + array[j+1];
				array[j+1] = array[j] - array[j+1];
				array[j] = array[j] - array[j+1];
				flag = 1;
			}
		}
		if (flag == 0){
			break;
		}
	}
}


void print_array(int* array, int n){

	for (int k=0; k<n; k++){
		printf("%i\t", array[k]);
	}
}

