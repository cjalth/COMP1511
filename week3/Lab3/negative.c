// Don't be so Negative
// negative.c
//
// This program was writen by Caitlin Wong (z5477471)
// on 15/06/2023
//
// This program gets a number from a user and prints whether it's
// negative, positive or equal to zero

#include <stdio.h>

int main(void) {

    int number;

    scanf("%d", &number);

    if (number < 0) {

        printf("Don't be so negative!\n");

    } else if (number > 0) {

        printf("You have entered a positive number.\n");

    } else {
        printf("You have entered zero.\n");
    }

    return 0;
}