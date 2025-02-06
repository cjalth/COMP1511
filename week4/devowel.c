// Devowelling Text
// devowel.c
//
// This program was writen by Caitlin Wong (z5477471)
// on 21/06/2023
//
// This program reads characters from its input and writes the 
// same characters to its output, except lower case vowels

#include <stdio.h>
#include <string.h>

int text(char letter) {
    return letter == 'a' ||
        letter == 'e' ||
        letter == 'i' ||
        letter == 'o' ||
        letter == 'u'; 
}


int main(void){
    char letter;

    while (scanf("%c", &letter) == 1) {
        if (!text(letter)) {
            printf("%c", letter);
        }
    }
    return 0;
}