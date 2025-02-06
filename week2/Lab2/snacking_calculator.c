// Snacking Calculator
// snacking_calculator.c
// A simple program that figures out how many slices of
// bread I can snack on while making sandwiches for my party!
//
// Written by Paula Tennent (z5255101) on 4/2/23
// Tested by Caitlin Wong (z5477471)


#include <stdio.h>

int main(void) {

    printf("How many slices of bread do you have? ");

    int slices;
    scanf("%d", &slices);

    int snack = 0;
    // if I have an odd number of slices, I can snack
    // on 1 slice.
    if (slices % 2 == 1) {
        snack = 1;
    }

    // if I have an even number of slices, I can snack
    // on 2 slices!
    if (slices % 2 == 0) {
        snack = 2;
        slices = slices - 2;
    }

    int sandy = slices / 2;

    printf("You can snack on %d slices of bread and make %d sandwiches!\n", snack, sandy);

    return 0;
}