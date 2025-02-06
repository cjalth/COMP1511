// Create a simple calculator, reading different numbers of integers
// cs_calculator.c
//
// This program was writen by Caitlin Wong (z5477471)
// on 22/06/2023
//
// This program scan in instructions until End-Of-Input 
// and prints the output as specified below. An instruction
// is a character, followed by one or two positive integers.
#include <stdio.h>

int main(void) {
    char instruction;
    int number1;
    int number2;
    printf("Enter instruction: ");

    while (scanf(" %c", &instruction) == 1) {
        if (instruction == 's') {
            scanf(" %d", &number1);
            int square = number1 * number1;
            printf("%d\n", square);
            printf("Enter instruction: ");
        } else if (instruction == 'p') {
            scanf(" %d %d", &number1, &number2);
            int i = 0;
            int power = 1;
            while (i < number2) {
                power = power * number1;
                i++;
            }
            printf("%d\n", power);
            printf("Enter instruction: ");
        }
    }
    return 0;
}