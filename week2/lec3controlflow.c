#include <stdio.h>
#include <stdbool.h> 
#define LEGAL_AGE 18
#define MIN_HEIGHT 100
#define MIN_HEIGHT_WITH_ADULT 70

int main(void) {

    // if statement needs a condition to execute if true
    // condition: something to evaluate as true of false
    // everything in {...} will run if true

    if(true) {
        printf("The condition was true!\n");
    }
    // else prints when the if statement doesn't run, optional, always with if statement cant be by itself
    else {
        printf("The condition was false!\n");
    }

   /* int user_age;

    printf("Enter your age (be honest pls): ");
    scanf("%d", &user_age);

    if(user_age > 0 && user_age < LEGAL_AGE) {
        printf("get lost, kid...\n");
    }
    if(user_age > LEGAL_AGE && user_age < 115) {
        printf("Here's a drink :)\n");
    }
    else {
        printf("You're lying...\n");
    } */

    int rider_height;

    printf("Are you tall enough to ride the rollercoaster?\n");
    printf("Enter your height: ");
    scanf("%d", &rider_height);

    if(rider_height < MIN_HEIGHT_WITH_ADULT) {
        printf("get lost kid...\n");
    }
    else if(rider_height < MIN_HEIGHT) {
        printf("You must have a guardian with you\n");
    }
    else {
        printf("You are good to go\n");
    }

    // while the expression is true, do something over and over
    // when block ends, jump back to the beginning of the while loop
    
    int number_of_lines = 5;
    int I = 0;
    
    while (I < number_of_lines) {
        printf("hey!\n");
        I = I + 1;
    }

    return 0;
}