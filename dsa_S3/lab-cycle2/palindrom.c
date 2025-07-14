#include <stdio.h>
#include <string.h>


int main(void){

	char string[100];
	printf("Enter a string: ");
	
	// reading string
	if (fgets(string, 100*sizeof(char), stdin)){
		string[strcspn(string, "\n")] = '\0';
	}
	
	// creating a stack
	char stack[100];
	
	// calculating its length
	int n = strlen(string);
	int top = n-1;
	
	int i = 0;
	while(string[i] != '\0'){
		stack[i] = string[i];
		i++;
	}
	
	// checking whether palindrom or not
	int flag = 0;
	for (int j=0; j<n; j++){
		if (string[j] == stack[top-j]){
			flag ++;
		}
	}
	
	if (flag == n){
		printf("Given string is palindrome\n");
		return 0;
	}
	
	printf("Given string is not palindrome\n");
	return 0;

}
