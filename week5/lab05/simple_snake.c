// A simpler version of the famous Snake game!
//
// Written by Rory Golledge (z5308772) on 3/3/23
// Modified by Caitlin Wong (z5477471) on 04-07-23
//
// This program is a simple snake game that spawns the snake 
// and apple, moves the snake using a loop and ends the game 
// when the snake reaches the apple. 

#include <stdio.h>

#define SIZE 8

enum land {
    NOT_VISITED,
    VISITED,
    SNAKE,
    APPLE
};

void initialise_map(enum land map[SIZE][SIZE]);
void print_map(enum land map[SIZE][SIZE]);

int main(void) {
    enum land map[SIZE][SIZE];
    initialise_map(map);
    int arow, acol, srow, scol;
 
    printf("Welcome to Snake!\n");

    // TODO: Complete the program

    printf("Please enter apple location: ");
    scanf("%d %d", &arow, &acol);

    printf("Please enter snake location: ");
    scanf("%d %d", &srow, &scol);

    map[arow][acol] = APPLE;
    map[srow][scol] = SNAKE;
    print_map(map);

    while (!(srow == arow && scol == acol)) {
        char command;
        scanf(" %c", &command);
        map[srow][scol] = VISITED;
        if (command == 'u') {
            srow--;
        } else if (command == 'd') {
            srow++;
        } else if (command == 'l') {
            scol--;
        } else if (command == 'r') {
            scol++;
        }
        map[srow][scol] = SNAKE;
        print_map(map);
    }

    printf("Chomp!\n");

    return 0;
}

/**
 * Initialises the given `map` such that all tiles are `NOT_VISITED`
 * 
 * Parameters:
 *     map - The map to initialise
 * 
 * Returns:
 *     Nothing
 */
void initialise_map(enum land map[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            map[row][col] = NOT_VISITED;
        }
    }
}

/**
 * Prints the given `map` such that all enum values are printed as nice
 * characters.
 * 
 * Parameters:
 *     map - The map to print out
 * 
 * Returns:
 *     Nothing
 */
void print_map(enum land map[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            if (map[row][col] == NOT_VISITED) {
                printf(". ");
            } else if (map[row][col] == VISITED) {
                printf("- ");
            } else if (map[row][col] == SNAKE) {
                printf("S ");
            } else if (map[row][col] == APPLE) {
                printf("A ");
            }
        }
        printf("\n");
    }
}
