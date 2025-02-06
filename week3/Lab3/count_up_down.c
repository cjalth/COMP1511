// Count Up/Down
// count_up_down.c
//
// This program was writen by Caitlin Wong (z5477471)
// on 15/06/2023
//
// This program reads an integer n and prints all integers 
// from 0 to n inclusive, one per line.

#include <stdio.h>

int main(void) {
    int number;
    printf("Enter number: ");
    scanf("%d", &number);

    if (number > 0) {
        int zero = 0;
        while (zero <= number) {
            printf("%d\n", zero);
            zero ++;
        } 
    }   
    else if (number < 0) {
        int zero = 0;
        while (zero >= number) {
            printf("%d\n", zero);
            zero--;
        }
    }
    return 0;
}