#include <stdio.h>
#include <time.h>

float mean_array(int* array, int n);
float median_array(int* array, int n);
int mode_array(int* array, int n);
void bubble_sort(int* array, int n);


int main(void){
	
	int array[] = {24, 67, 98, 23, 45, 12, 18, 24};
	int n = 8;
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
	
	printf("Mean of the array = %f\n", mean);
	printf("Time taken for calculating mean is %f\n\n", time_used);
	
	
	// starting time calculation for median
	start = clock();
	
	// Finding median
	float median = median_array(array, n);
	
	// stopping time calculation for median
	end = clock();
	
	// calculating time taken for median
	time_used = ((double)(end-start))/CLOCKS_PER_SEC;
	
	printf("Median of the array = %f\n", median);
	printf("Time taken for calculating median is %f\n\n", time_used);
	
	
	// starting time calculation for mode
	start = clock();
	
	// Finding mode
	int mode = mode_array(array, n);
	
	// stopping time calculation for mode
	end = clock();
	
	// calculating time taken for mode
	time_used = ((double)(end-start))/CLOCKS_PER_SEC;
	
	printf("Mode of the array is %i\n", mode);
	printf("Time taken for calculating median is %f\n\n", time_used);
	

	return 0;
}


float mean_array(int* array, int n){
	
	int total = 0;	
	for (int i=0; i<n; i++){
		total += array[i];  // We dont need the * opeartor for dereference of array. Analog it with int array[10]. 
	}
	return ((float)total)/n;
}


float median_array(int* array, int n){
	// median is the middle most element of the array, when written in increasing order.
	// So lets bubble sort it.
	bubble_sort(array, n);

	// If array contains odd number of elements, then median is (n+1)/2 th elements, and its index will be n/2
	if (n%2 != 0){
		return array[n/2];
	}
	else{
		int median = (array[(n-1)/2] + array[n/2])/2;
		return median;
	}
}


int mode_array(int* array, int n){

	// Its the more frequent element in the array
	int mode;
	int Maxcount = 0;

	// Lets find the count of each element in that array
	for (int i=0; i<n; i++){

		// finding count of one element
		int count = 0;
		for (int j=0; j<n; j++){
			if (array[i] == array[j]){
				count++;
			}
		}

		// checking whether update mode or not
		if (count > Maxcount){
			Maxcount = count;
			mode = array[i];
		}
	}

	return mode;
}


void bubble_sort(int* array, int n){

	for (int i=0; i<n-1; i++){
		int flag = 0;
		for (int j=0; j<n-1-i; j++){
			flag = 1;
			if (array[j] > array[j+1]){
				array[j] = array[j] + array[j+1];
				array[j+1] = array[j] - array[j+1];
				array[j] = array[j] - array[j+1];
			}
		}
		if (flag == 0){
			break;
		}
	}
}












































