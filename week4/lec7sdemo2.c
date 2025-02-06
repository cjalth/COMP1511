#include <stdio.h>
#include <string.h>
#define MAX_LEN 100

int main(void){
    char first_name[MAX_LEN];
    char last_name[MAX_LEN];

    printf("Enter first name: ");
    fgets(first_name, MAX_LEN, stdin);

    printf("Enter last name: ");
    fgets(last_name, MAX_LEN, stdin);

    char full_name[MAX_LEN] 

    // replaces '\n' with a space 
    first_name[strlen(first_name) - 1] = ' ';

    strcpy(full_name, strcat(first_name, last_name));

    // prints new line so use previous demo trick to avoid (line 18)
    fputs(full_name, stdout);

    return 0;
}