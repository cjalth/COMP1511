// Does some calculations to make souffle pancakes
// Solution by Paula Tennent (2023)
// Solution fixed by Caitlin Wong (z5477471)

#include <stdio.h>

#define COOKING_TIME 15
#define PANCAKES_PER_PAN 4

// TODO: Write function prototypes
double divide(double top, double bottom);
int ceiling(double cnumber);
void print_time(int pminutes);

// TODO: Write divide function
double divide(double top, double bottom) {
    double result = top / bottom; 
    return result;
}

// TODO: Write ceiling function
int ceiling(double cnumber) {
    int result = cnumber;
    if (cnumber - result == 0) {
        return result;
    } else {
        cnumber = result + 1;
        return cnumber;
    }

}

// TODO: Write print_time function
void print_time(int pminutes) {
    int hours = pminutes / 60;
    if(pminutes > 60) {
        pminutes = pminutes % 60;
    }
    printf("%d hours and %d minutes", hours, pminutes);

}

//////////////// vvv DO NOT EDIT MAIN vvv //////////////////

int main(void) {

    printf("How many souffle pancakes do you want to make? ");
    int pancakes;
    scanf("%d", &pancakes);
  
    // for 3 pancakes, we need 2 eggs!
    double eggs_decimal = pancakes * divide(2, 3);
    // but we can't have part of an egg, so lets use ceiling
    int eggs = ceiling(eggs_decimal);

    int sugar_grams = pancakes * 10;
    int flour_grams = pancakes * 8;

    printf("You will need:\n");
    printf("- %d eggs\n", eggs);
    printf("- %dg sugar\n", sugar_grams);
    printf("- %dg flour\n", flour_grams);

    // also using ceiling for frying sessions as if we have 1 pancake left
    // it still needs the same time as full pan of pancakes.
    int frying_sessions = ceiling(divide(pancakes, PANCAKES_PER_PAN));
    int minutes = frying_sessions * COOKING_TIME;

    printf("Frying will take you ");
    print_time(minutes);
    printf(".\n");

    return 0;
}

//////////////// ^^^ DO NOT EDIT MAIN ^^^ //////////////////
