#include <stdio.h>
#define MAX_LENGTH 50

int main(void) {
    // asking for 8bits * MAX_LENGTH (50)
    char name[MAX_LENGTH]; 

    // strlen() -> gives us the length of the string (excluding the \0 ).
    // strcopy() -> copy the contents of one string to another
    // strcat() -> join one string to the end of another (concatenate)
    // strcmp() -> compare two strings
    // strchr() -> find the first or last occurrence of a character
    // note: some of these may require #include <string.h>

    strcpy(name, "jake");

    while(fgets(name, MAX_LENGTH, stdin); != NULL) {
        printf("Enter your name: ");
    }

    return 0;
}