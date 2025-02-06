// Encrypting Text with a Substitution Cipher
// substitution.c
//
// Written by Caitlin Wong (z5477471)
// on 15/07/2023
//
// This program reads characters from its input and writes the 
// characters to its output, encrypted with a substitution cipher.

#include <stdio.h>
#include <string.h>

int encrypt(int letter, char argv[]);

int main(int argc, char *argv[]) {

    printf("Enter text:\n");

    int letter = getchar();
    int i = 1;
    while (letter != EOF) {
        int encrypted = encrypt(letter, argv[i]);
        putchar(encrypted);
        letter = getchar();
    }

    return 0;
}

int encrypt(int letter, char argv[]) {
    if (letter <= 'Z' && letter >= 'A') {
        return argv[letter - 'A'] - 'a' + 'A';
    } else if (letter <= 'z' && letter >= 'a') {
        return argv[letter - 'a'];
    } else {
        return letter;
    }
}