#include <stdio.h>
# include <time.h>

void rotate_array(int* a, int n, char dir, int count);
void print_array(int* a, int n);

int main(){

	int array[] = {23, 24, 25, 26, 27, 28};
	int n = 6;
	clock_t startL, endL, startR, endR;
	double time_used;
	
	// original array
	printf("Original array\n");
	print_array(array, n);
	printf("\n\n");
	
	// Starting time calculation for left rotaion.
	startL = clock();
	
	// Rotating 3 times towards left
	rotate_array(array, n, 'l', 3);
	
	// Ending time calculation
	endL = clock();
	
	printf("3 times Left rotated array\n");
	print_array(array, n);
	printf("\n");
	
	// calculating time calculation towards left
	time_used = ((double)(endL-startL))/CLOCKS_PER_SEC;
	printf("Time taken for 3 times left rotation is %f seconds\n\n", time_used);
	
	// starting timetaken for right rotation
	startR = clock();
	
	// Rotating 4 times towards right
	rotate_array(array, n, 'r', 4);
	
	// Ending time alculation
	endR = clock();
	
	printf("4 times Right rotated array\n");
	print_array(array, n);
	printf("\n");
	
	// calculating time calculation towards right
	time_used = ((double)(endR-startR))/CLOCKS_PER_SEC;
	printf("Time taken for 4 times right rotation is %f seconds\n\n", time_used);
	
	return 0;
}


void rotate_array(int* a, int n, char dir, int count){
	
	if (dir == 'l'){
	
		for (int i=0; i<count; i++){
			int first = a[0];
			for (int j=0; j<n-1; j++){
				a[j] = a[j+1];
			}
			a[n-1] = first;
		}
	}
	
	
	if (dir == 'r'){
		
		for (int i=0; i<count; i++){
			int last = a[n-1];
			for (int j=0; j<n-1; j++){
				a[n-j-1] = a[n-j-2];
			}
			a[0] = last;
		}
	}
}


void print_array(int* a, int n){
	
	for (int k=0; k<n; k++){
		printf("%i\t", a[k]);
	}
}













