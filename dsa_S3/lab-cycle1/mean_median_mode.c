#include <stdio.h>
#include <time.h>

int mean_array(int* array, n);


int main(){
	
	int array[] = {24, 67, 98, 23, 45, 12, 18};
	int n = 7;
	clock_t start, end;
	double time_used;
	
	// starting time calculation for mean
	start = clock();
	
	// Finding mean
	float mean = mean_array(array, n);
	
	// stopping time calculation for mean
	end = clock();
	
	// calculating time calculation for mean
	time_used = ((double)(end-start))/CLOCKS_PER_SEC;
	
	printf("Mean of the array = %f\n", mean)
	printf("Time taken for calculating mean is %f\n\n", time_used);
	
	
	// starting time calculation for median
	start = clock();
	
	// Finding median
	int median = median_array(array, n);
	
	// stopping time calculation for median
	end = clock();
	
	// calculating time taken for median
	time_used = ((double)(end-start))/CLOCKS_PER_SEC;
	
	printf("Median of the array = %i\n", median)
	printf("Time taken for calculating median is %f\n\n", time_used);
	
	
	// starting time calculation for mode
	start = clock();
	
	// Finding mode
	int mode = mode_array(array, n);
	
	// stopping time calculation for mode
	end = clock();
	
	// calculating time taken for mode
	time_used = ((double)(end-start))/CLOCKS_PER_SEC;
	
	printf("Mode of the array = %i\n", mode)
	printf("Time taken for calculating median is %f\n\n", time_used);
	
	
	return 0;
}


int mean_array(int* array, n){
	
	total = 0;	
	for (int i=0; i<n; i++){
		total += array[i];
	}
	return ((float)total)/n;
}












































