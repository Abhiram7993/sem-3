#include <stdio.h>
#include <time.h>

void bubble_sort(int* array, int n);
void print_array(int* array, int n);
void flush(void);
void binary_search(int* array, int n, int data);


int main(void){

	int array[100];
	int len;
	clock_t start, end;
	double cpu_time_used;

    // Adding elements to array
	printf("Enter number of elements: ");
	scanf("%i", &len);
	flush();

	for (int i=0; i<len; i++){
		printf("Enter number: ");
		scanf("%i", &array[i]);
		flush();
	}
	// Sorting the array
	bubble_sort(array, len);

    int search;
    printf("Element to search: ");
    scanf("%i", &search);
    flush();

    // starting time calculation
    start = clock();
	
	// searching an element in the array via binary search
    binary_search(array, len, search);
	
    // stopping time calculation
    end = clock();

    // Calculating timetaken in seconds
    cpu_time_used = ((double)(end - start))/CLOCKS_PER_SEC;

    printf("Time used for binary search is %f seconds.\n", cpu_time_used);
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


void binary_search(int* array, int n, int data){
    
    int left = 0;
    int right = n-1;
    
    while (left <= right){
        int mid = (left + right)/2;

        if (array[mid] = data){
            printf("Element find at index %i.\n", mid);
            return;
        }

        else if (array[mid] > data){
            right = mid - 1;
            continue;
        }

        else{
            left = mid + 1;
            continue;
        }
    }
    printf("ELement is not at array.\n");
    return;
}