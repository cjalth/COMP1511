// Summation
// summation.c
//
// Written by Caitlin Wong (z5477471)
// on 13/07/2023
//
// This program takes integers as command line 
// argumants and calculates their sum.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int arg = 1;
    int number = 0;

    while (arg < argc) {
        int add = atoi(argv[arg]);
        number = number + add;
        arg++;
    }

    printf("Sum: %d\n", number);

    return 0;
}