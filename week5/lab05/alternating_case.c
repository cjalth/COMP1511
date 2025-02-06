// Written by Caitlin Wong (z5477471)
// July, 2023
// This program takes a string a modifies it so that 
// the case of each letter alternates. 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STRING_LENGTH 1024

//////////////// DO NOT CHANGE ANY OF THE CODE BELOW HERE //////////////////
void make_alternating(char string[MAX_STRING_LENGTH]);

int main (void) {
    //You don't need to understand this code to complete the exercise.

    //Scans in a string from the user.
    char buffer[MAX_STRING_LENGTH];
    fgets(buffer, MAX_STRING_LENGTH, stdin);

    // Runs your function
    make_alternating(buffer);

    // Prints resulting string.
    printf("%s", buffer);

    return 0;
}
//////////////// DO NOT CHANGE ANY OF THE CODE ABOVE HERE //////////////////

////////////////////////////////////////////////////////////////////////////
///////////////////// ONLY WRITE CODE BELOW HERE ///////////////////////////
////////////////////////////////////////////////////////////////////////////

// Modifies `string` so that the first letter is converted to lowercase, 
// and the case of each following letter alternates.
// i.e. in the resulting string: 
//      the first letter is lowercase, 
//      second letter is uppercase, 
//      third letter is lower case, 
//      etc.
//
// e.g.: "Hello" -> "hElLo"
void make_alternating(char string[MAX_STRING_LENGTH]) {
    // TODO: complete this function
    int letters = 0;
    int i = 0;
    while (string[i] !='\0') {
        // remember isalpha checks if it's an alphabet or not
        if (isalpha(string[i])) {
            if (letters % 2 == 0) {
                // gives char to lowercase
                string[i] = tolower(string[i]);
            } else {
                // gives char to uppercase
                string[i] = toupper(string[i]);
            }
            letters++;
        }
        i++;
    }
}

////////////////////////////////////////////////////////////////////////////
///////////////////// ONLY WRITE CODE ABOVE HERE ///////////////////////////
////////////////////////////////////////////////////////////////////////////
