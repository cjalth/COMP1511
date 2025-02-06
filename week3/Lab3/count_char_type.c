// Count Character Type
// count_char_type.c
//
// This program was writen by Caitlin Wong (z5477471)
// on 15/06/2023
//
// This program reads a sequence of alphabetical characters and prints 
// the count of consonants and vowels in the sequence.

#include <stdio.h>

int main(void) {
    printf("Enter a sequence of characters: ");
    char letter;
    int vowelsum = 0;
    int consonantsum = 0;

    while (scanf("%c", &letter) && letter != '\n') {
        if (letter < 'A' || (letter > 'Z' && letter < 'a' ) || letter > 'z') {
            vowelsum = vowelsum + 0;
        }
        else if (letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || 
        letter == 'U' || letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o'
        || letter == 'u') {
            vowelsum = vowelsum + 1;
        }
        else {
            consonantsum = consonantsum + 1;
        }
    }     
    
    printf("Number of vowels: %d\n", vowelsum);
    printf("Number of consonants: %d\n", consonantsum);

    return 0;
}
