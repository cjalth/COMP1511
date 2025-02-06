// Print a Coordinte Grid
// print_grid.c
//
// This program was writen by Caitlin Wong (z5477471)
// on 15/06/2023
//
// This program reads an integer 'n' and prints an 'n x n' grid 
// with all the coordinates of the grid shown.

#include <stdio.h>

int main(void) {
    printf("Enter size: ");
    int size;
    scanf("%d", &size);
    int row = 0;
    while (row < size) {
        int col = 0;
        while (col < size) {
            printf("(%d,%d) ", row, col);
            col ++;
        } 
        printf("\n");
        row ++;

    } return 0;
}
