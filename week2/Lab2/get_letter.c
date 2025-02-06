// Print Letters, Given Their Numbers
// get_letter.c
//
// This program was writen by Caitlin Wong (z5477471)
// on 08/06/2023
//
// This program prints a letter depending on the user's request.

#include <stdio.h>

int main(void) {

    char is_uppercase;
    printf("Uppercase: "); 
    scanf("%c", &is_uppercase);

    // TODO: scan is_uppercase

    int index;
    printf("Index: ");
    scanf("%d", &index);

    // TODO: finish the program

    if (is_uppercase == 'y') {
        printf("The letter is %c\n", index + 65);
    }
    else if (is_uppercase == 'n') {
        printf("The letter is %c\n", index + 97);
    }

    return 0;
}