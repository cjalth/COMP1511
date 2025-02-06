#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 50

int main(void){
    char animal[MAX_LENGTH];

    printf("Enter the animal name: ");
    // read a string into animal, from stdin
    // always reads in \n
    // 'o', 't', 't', 'e', 'r', '\n' 
    fgets(animal, MAX_LENGTH, stdin);

    int animal_str_len = strlen(animal);
    animal[animal_str_len - 1] = '\0';
    printf("%d\n", animal_str_len);

    fputs(animal, stdout);

    return 0;
}