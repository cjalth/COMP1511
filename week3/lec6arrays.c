#include <stdio.h>
#define MAX_ROLLS 5

// reads in an int from uder, checks if it is between 1 and 6
// returns the roll, else asks again.
int get_dice_roll_from_user(void) {
    printf("Enter your roll: ");
    int result;
    scanf("%d", &result);

    while (result < 1 || result > 6) {
        printf("Try again: ");
        scanf("%d", &result);
    }

    return result;
}

void print_dice_rolls(int rolls[MAX_ROLLS]) {
    int i = 0;
    while(i < MAX_ROLLS){
        printf("%d\n", dice_rolls);
    }

}

int main(void) {

    // This creates an int array of 5 elements (index 0..4)
    // Set all elements to 0

    int dice_rolls[MAX_ROLLS] = {};
    int i = 0;

    while(i < MAX_ROLLS) {
        
        dice_rolls[i] = get_dice_roll_from_user();
        i = i + 1;

    }

    dice_rolls[0] = get_dice_roll_from_user();

    // prints the first element in the array
    printf("%d\n", dice_rolls[0]);


    return 0;
}