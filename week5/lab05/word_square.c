// Word Square
// word_square.c
//
// Written by Caitlin Wong (z5477471) and Anna Yang (z5479646)
// on 10/07/2023
//
// This program prompts the user to enter a word, and afterwards, 
// prints that word out n amount of times, where n is the length of the word.

#include <stdio.h>
#include <string.h>

#define MAX_CHAR 1024

int main(void) {
    char word[MAX_CHAR];
    int i = 0;

    printf("Input word: ");
    fgets(word, MAX_CHAR, stdin);
    printf("\nWord square is: \n");
    while (i < strlen(word) - 1) {
        printf("%s", word);
        i++;
    }

    return 0;
}