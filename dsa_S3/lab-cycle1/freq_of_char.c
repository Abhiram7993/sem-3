#include <stdio.h>
#include <string.h>


int main(void){
    char string[100];
    printf("Enter a string: ");

    // reading string
    if (fgets(string, 100*sizeof(char), stdin)){
        string[strcspn(string, "\n")] = '\0';
    }

    // an array for saving unique characters.
    char unique[100];
    int un = -1;

    // an array for saving the frequency of unique characters, sync with character array.
    int frequency[100];
    
    int i = 0;
    int N = strlen(string);

    while (i<N){

        // checking whether is it first occurance or not
        int isunique = 1;
        for (int j=0; j<=un; j++){
            if (string[i] == unique[j]){
                isunique = 0;
            }
        }
        if (!isunique){
            i++;
            continue;
        }
        // New element is adding to unique.
        un ++;
        unique[un] = string[i];
        int count = 0;
        for (int k=0; k<N; k++){
            if (string[i] == string[k]){
                count ++;
            }
        }
        frequency[un] = count;
        i++;
    }

    // printing unique characters and their frequency
    for (int m=0; m<=un; m++){
        printf("%c: %i\n", unique[m], frequency[m]);
    }
}
