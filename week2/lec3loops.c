#include <stdio.h>
#include <stdlib.h>

int main(void) {

    char input_char;
    printf("Enter your command: ");
    scanf(" %c", &input_char);

    // while the expression is true, do something over and over
    // when block ends, jump back to the beginning of the while loop

    while (input_char == 'r') {

        // generates a random number
        int random_num = (rand() % 6) +1;

        printf("You rolled a ... %d\n", random_num);
        printf("Enter your command: ");
        scanf(" %c", &input_char);
    }

    return 0;
}

