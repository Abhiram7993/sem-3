#include <stdio.h>
#include <string.h>

int main(void){
    char name[30];
    printf("Enter name: ");

    // reading name, fgets read until it hits \n or prescribed size. 
    // So it read only 30 bytes and avoid buffer overflow 
    // stdin represents read from terminal
    // In fgets the first arg is the address of the loaction where we want to save data
    if (fgets(name, sizeof(name), stdin)){
        // if reading happened then removing \n with '\0' to terminate
        // strcspn will return the index of a character in a string
        // in strcspn pass string as argument.
        name[strcspn(name, "\n")] = '\0';
    }

    printf("Welcome %s\n", name);
    return 0;
}