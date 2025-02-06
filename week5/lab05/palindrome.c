// palindrome.c
//
// Given a string, this program calculates whether it is palindromic or not and 
// prints out the result.
//
// Written by Caitlin Wong, z5477471
// on 04/07/2023

#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 1024

int is_palindrome(char my_string[MAX_STRING_LENGTH]);

//////////////// DO NOT CHANGE ANY OF THE CODE BELOW HERE //////////////////
int main (void) {
    // You don't need to understand this code to complete the exercise.

    // Scans in a string from the user.
    char my_string[MAX_STRING_LENGTH];
    fgets(my_string, MAX_STRING_LENGTH, stdin);

    // removing the newline character from the end of the string
    int length = strlen(my_string);
    if (length != 0 && my_string[length - 1] == '\n') {
        my_string[length - 1] = '\0';
    }
    
    // Runs your function and prints results
    if (is_palindrome(my_string)) {
        printf("%s is a palindrome!\n", my_string);
    } else {
        printf("%s is not a palindrome!\n", my_string);
    }
    
    return 0;
}
//////////////// DO NOT CHANGE ANY OF THE CODE ABOVE HERE //////////////////

////////////////////////////////////////////////////////////////////////////
///////////////////// ONLY WRITE CODE BELOW HERE ///////////////////////////
////////////////////////////////////////////////////////////////////////////

// Determines if the given `my_string` is a palindrome or not.
// Returns `1` if it is, otherwise `0`
int is_palindrome(char my_string[MAX_STRING_LENGTH]) {
    // TODO: Write is_palindrome function here
    int i = 0;
    int length = strlen(my_string);
    while (i < length / 2) {
        if (my_string[i] != my_string[length - i - 1]) {
            return 0;
        }
        i++;
    }
    return 1;
}

////////////////////////////////////////////////////////////////////////////
///////////////////// ONLY WRITE CODE ABOVE HERE ///////////////////////////
////////////////////////////////////////////////////////////////////////////
