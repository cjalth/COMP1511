// Scanning numbers into an array
// scanning_into_array_style.c
//
// This program was writen by Caitlin Wong (z5477471)
// on 21/06/2023
//
// This program scans in a certain amount of numbers 
// from the user and fills an array with them.

#include <stdio.h>

#define MAX_SIZE 100

// Given an integer array, iterate over the array and print the minimum and
// maximum values in the array.
void print_array_minmax(int length, int numbers[MAX_SIZE]);

int main(void) {
    // TODO: Create an integer array of size MAX_SIZE
    // HINT: Do not use the user input as the length of the array!
    int thenumbers[MAX_SIZE];
    int numberlength;
    int amountlength = 0;
    int values;


    printf("How many numbers: ");
    // TODO: Fill in code that takes the quantity of numbers from the user
    scanf("%d", &numberlength);

    printf("Please enter numbers: ");
    // TODO: Fill in code that scans in integers from the user
    while (amountlength < numberlength) {
        scanf("%d", &values);
        thenumbers[amountlength] = values;
        amountlength = amountlength + 1;
    }
    
    print_array_minmax(numberlength, thenumbers);
    // TODO: Change this statement to match your variables and array.
    //      Refer to the documentation below for correct usage!

    return 0;
}

//////////////////////// DO NOT CHANGE THE CODE BELOW! ////////////////////////

// Given an integer array, iterate over the array and print the minimum and
// maximum values in the array.
//
// Takes in:
// - `length` -- The length of the array.
// - `numbers[MAX_SIZE]` -- The integer array to iterate over.
//
// Returns: nothing.
void print_array_minmax(int length, int numbers[MAX_SIZE]) {
    int index = 0;
    if (length > 0) {
        int minimum = numbers[index];
        int maximum = numbers[index];

        while (index < length) {
            if (numbers[index] < minimum) {
                minimum = numbers[index];
            } else if (numbers[index] > maximum) {
                maximum = numbers[index];
            }
            
            index++;
        }

        printf("Minimum: %d\nMaximum: %d\n", minimum, maximum);
    }
    
    return;
}