// Custom Printing Facces
// print_faces.c
//
// Written by Caitlin Wong (z5477471)
// on the 08/06/2023
// 
// A program that creates a face based on input

#include <stdio.h>

int main(void) {
    char eyes1;
    char eyes2;
    char nose;
    char mouth;

    printf("How do you want to build a face?: ");
    scanf("%c%c%c%c", &eyes1, &eyes2, &nose, &mouth);

    if (mouth == '\n') {
        nose = mouth;
        eyes2 = nose;
        if (eyes1 == 'a' ) {
        printf("_ _\n");
        printf("O O\n");
    } else if (eyes1 == 'b') {
        printf("~ ~\n");
        printf("O O\n");
    } else if (eyes1 == 'c') {
        printf("\\ \\\n");
        printf("O O\n");
    } else if (eyes1 == 'd') {
        printf("/ /\n");
        printf("O O\n");
    }
    } 
        if (eyes1 == 'a') {
        printf("_ ");
    } else if (eyes1 == 'b') {
        printf("~ ");
    } else if (eyes1 == 'c') {
        printf("\\ ");
    } else if (eyes1 == 'd') {
        printf("/ ");
    }
    if (eyes2 == 'a') {
        printf("_\n");
    } else if (eyes2 == 'b') {
        printf("~\n");
    } else if (eyes2 == 'c') {
        printf("\\\n");
    } else if (eyes2 == 'd') {
        printf("/\n");
    }
    
    printf("O O\n");
    if (nose == 'e') {
        printf(" ^\n");
    } else if (nose == 'f') {
        printf(" ~\n");
    }

    if (mouth == 'g') {
        printf("\\_/\n");
    } else if (mouth == 'h') {
        printf("/-\\\n");
    } else if (mouth == 'i') {
        printf(" o\n");
    }

    return 0;
}