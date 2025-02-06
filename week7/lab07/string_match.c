// String Match
// string_match.c
//
// Written by Caitlin Wong (z5477471)
// on 12/07/2023
//
// This program counts the number of times a "search term"
// is seen in a list of strings.

#include <stdio.h>
#include <string.h>

#define MAX_CHAR 128

int main(void) {
    char word[MAX_CHAR];
    char search_words[MAX_CHAR];

    printf("Enter the search term: ");
    fgets(word, MAX_CHAR, stdin);

    printf("Enter the list of strings: \n");
    int total = 0;

    while (fgets(search_words, MAX_CHAR, stdin) != NULL) {

        if(strcmp(search_words, word) == 0) {
            total++;
        }
    }

    printf("There was %d occurrence(s) of the search term "
            "in the input.\n", total);

    return 0;
}
