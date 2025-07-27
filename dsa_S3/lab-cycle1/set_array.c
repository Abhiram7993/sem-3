#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void get_set(int* set, int* n);
void flush(void);


int main(void){
    int S1[100];
    int s1_len; // saves the total element in array.
    get_set(S1, &s1_len);

    int S2[100];
    int s2_len;
    get_set(S2, &s2_len);

    int INTERSECTION[100];
    int intersection_len = 0;
    
    // for finding common elements in both sets
    for (int i=0; i<s1_len; i++){
        for (int j=0; j<s2_len; j++){
            if (S1[i] == S2[j]){
                INTERSECTION[intersection_len] = S1[i];
                intersection_len++;
            }
        }
    }

    // Dont worry about repeatition elements in array, it can be blocked in get_set()
    printf("Intersection of S1 and S2: \n");
    printf("{  ");
    for (int k=0; k<intersection_len; k++){
        printf("%i ", INTERSECTION[k]);
    }
    printf(" }\n");
    return 0;
}


void get_set(int* set, int* n){
    printf("Number of elements: ");
    scanf("%i", n);
    flush();

    for (int i=0; i<*n; i++){
        int temp;
        printf("Enter number: ");
        scanf("%i", &temp);
        flush();
        set[i] = temp;
    }
}


void flush(void){
    int c;
    c = getchar();
    if ((c != '\n')&&(c != EOF)){
        c = getchar();
    }
}