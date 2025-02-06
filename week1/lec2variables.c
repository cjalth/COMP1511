#include <stdio.h>

int main(void) {
    // variable is a character (eg. 'a')
    char my_char;
    //integer reading the variabel of height (can only be a whole number)
    int height;
    // Integer with a decimal point use double not int
    double max_kg_bicep_curl;

    my_char = 'j';
    // the varibale is height and it's 175
    height = 175;
    // the variable
    max_kg_bicep_curl = 450.5;

    //printf printing the sentence with the variable 'height'
    // %d for ints "decimal integer"
    // %lf for "log floating point number" (a double)
    // %c is for a character
    printf("%c is %dcm tall and lifts %lfkg!\n", my_char, height, max_kg_bicep_curl);

    return 0;
}