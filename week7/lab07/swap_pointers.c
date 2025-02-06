// Using pointers and a function to swap number values
// swap_pointers.c
//
// Written by Caitlin Wong (z5477471)
// on 12/07/2023
//
// This program takes 2 pointers to integers as input and
// swaps the values stored in those two integers.

#include <stdio.h>

void swap_pointers(int *a, int *b);

// This is a simple main function which could be used
// to test your swap_pointers function.
// It will not be marked.
// Only your swap_pointers function will be marked.

int main(void) {
    int first = 1;
    int second = 2;
    
    swap_pointers(&first, &second);
    
    printf("%d, %d\n", first, second);
    return 0;
}

// swap the values in two integers, given as pointers
void swap_pointers(int *a, int *b) {
    // PUT YOUR CODE HERE
    int value = *a;
    *a = *b;
    *b = value;
}
