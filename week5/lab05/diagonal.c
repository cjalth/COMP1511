// diagonal.c
//
// Given a 2D array, this programs calculates the sum of elements on a diagonal
// i.e top left to bottom right 
//
// Written by Caitlin Wong (z5477471)
// 10/07/2023

#include <stdio.h>

#define ARRAY_MAX_SIZE 100

int diagonal_sum(int array[ARRAY_MAX_SIZE][ARRAY_MAX_SIZE], int size);

//////////////// DO NOT CHANGE ANY OF THE CODE BELOW HERE //////////////////
int main(void) {

    int array[ARRAY_MAX_SIZE][ARRAY_MAX_SIZE];
    int size;

    printf("Please enter the size of your square array: ");
    scanf("%d", &size);

    // scans numbers into the array
    printf("Please enter the values for your array: ");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &array[i][j]);
        }
    }

    printf("The sum of the diagonal is %d\n", diagonal_sum(array, size));

    return 0;
}
//////////////// DO NOT CHANGE ANY OF THE CODE ABOVE HERE //////////////////

////////////////////////////////////////////////////////////////////////////
///////////////////// ONLY WRITE CODE BELOW HERE ///////////////////////////
////////////////////////////////////////////////////////////////////////////

int diagonal_sum(int array[ARRAY_MAX_SIZE][ARRAY_MAX_SIZE], int size) {
    int row = 0;
    int total_sum = 0;
    // Looks through the rows and columns of the array
    while (row < size) {
        int col = 0;
        while (col < size) {
            // If the row and column are the same number, add them together
            if (row == col) {
                total_sum = total_sum + array[row][col];
            }
            col++;
        }
        row++;
    }
    // returns the total of the diagonal 
    return total_sum;
}

////////////////////////////////////////////////////////////////////////////
///////////////////// ONLY WRITE CODE ABOVE HERE ///////////////////////////
////////////////////////////////////////////////////////////////////////////
