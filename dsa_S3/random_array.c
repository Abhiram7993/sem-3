#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
    
    // Our aim is to generate a random array of 10 numbers less than 10.
    int random[10];
    
    // Lets set a seed to srand()
    // It is essential to generate diff sequence on diff calls by rand()
    // Here I am setting current time (time(0)) as seed, Since it change always.
    srand(time(0));

    // Adding elements to array
    for (int i=0; i<10; i++){
        // since rand() generate any random number and we need numbers less than 100.
        // we can use % 100
        int random_number = rand()%100;
        random[i] = random_number;
    }

    for (int j=0; j<10; j++){
        printf("%i\t", random[j]);
    }
    printf("\n");
    return 0;
}

// here we will get random number in each call, this is bcuz 
// we call rand() after setting a seed on srand().
// Hence it will generate diff sequence on each call.