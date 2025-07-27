#include <stdio.h>
#include <time.h>

void bubble_sort(int* array, int n);
void print_array(int* array, int n);
void flush(void);


int main(){

	int array[100];
	int len;
	clock_t start, end;
	double cpu_time_used;

	printf("Enter number of elements: ");
	scanf("%i", &len);
	flush();

	for (int i=0; i<len; i++){
		printf("Enter number: ");
		scanf("%i", &array[i]);
		flush();
	}
	
	// starting time calculation.
	start = clock();
	
	bubble_sort(array, len);
	
	// ending time calculation.
	end = clock();
	
	print_array(array, len);
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


void flush(void){
	int c = getchar();
	while (c!='\n' && c!=EOF){
		c = getchar();
	}
}