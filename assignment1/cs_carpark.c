// CS Carpark
//
// This program was written by Caitlin Wong (z5477471)
// on 21/06/2023
//
// This program simulates a carpark. 

#include <stdio.h>
#include <math.h>

// Provided constants
#define CARPARK_ROWS 8
#define CARPARK_COLUMNS 6
#define NORMAL_PARKING_RATE 10
#define EMPTY -1

// Your constants here 
#define PREMIUM_PARKING_RATE 50
#define CHARGING_RATE 7
#define CARWASH_RATE 15
#define PRINT_CARPARK 'P'
#define NEW_PARKING 'p'
#define TOTAL_PARKING 'o'
#define FREE_SPACES 'F'
#define DISCOUNT 'd'
#define FIND_CAR 'f'
#define LEAVE_CARPARK 'l'
#define CHARGE_STATION 'e'
#define MOVE_CAR 'm'
#define CHARGE_CAR 'c'
#define CARWASH_BUILD 'w'
#define PARK_HISTORY 'h'

// Provided enums
enum space_type {
    NORMAL,
    PREMIUM,
    CARWASH_BAY,
    ELECTRIC_CHARGING_STATION,
    ELEC_IN_USE,
    IN_USE
};


// Provided structs
struct car_space {
    enum space_type type;
    int p_parking_rate;
    int parking_rate;
    int licence_plate;
    int occupied_since;
    int leave_time;
    int cable_length;
    int charging_rate;
    int charging;
    int carwash_rate;
    int total_price;
    int total_time;
    int empty;
};

////////////////////////////////////////////////////////////////////////////////
////////////////////////  YOUR FUNCTION PROTOTYPE  /////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// TODO: Put your function prototypes here
// Stage 1 functions:
void premium_parking(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS]);
void initial_cars(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS]);
void parking_commands(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS]);
void new_parking(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS]);
void park_new_car(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS],
int licence_plate_no, int row, int col, int time_of_entry);
void count_total(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS]);

// Stage 2 functions:
void free_spaces(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS]);
void discounts(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS]);
void find_car(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS]);
void leave_carpark(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS]);
void leaving_specifics(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS]
, int total_time, int licence_plate_no, int row, int col);

// Stage 3 functions:
void charging_station(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS]);
void charge_car(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS]);
void find_charger(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS]
, int row, int col, int charge_till, int charge_from, int licence_plate_no);
void cable_length(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS],
 int i, int j, int licence_plate_no, int charge_till, int charge_from, int row,
 int col);
int other_chargers(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS], 
int row, int col, int licence_plate_no, int charge_from, int charge_till, 
double distance);
void shortest_time(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS],
int i, int j, int licence_plate_no, int charge_till, int charge_from, int row,
int col);
void move_car(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS]);
void move_car_works(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS]
, int time_of_move, int new_row, int new_col, int row, int col, 
int licence_plate_no);
void car_moving_in(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS],
int time_of_move, int new_row, int new_col, int row, int col, 
int licence_plate_no);
void print_car_moved(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS],
int time_of_move, int new_row, int new_col, int row, int col, 
int licence_plate_no);
void carwash_bay(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS]);
int surroundings_of_bay(struct car_space carpark[CARPARK_ROWS]
[CARPARK_COLUMNS], int row, int col, int empty);
void use_carwash(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS],
int licence_plate_no, int row, int col, int time_of_entry);
int use_surroundings(struct car_space carpark[CARPARK_ROWS]
[CARPARK_COLUMNS], int row, int col, int empty);
int check_carwash_corners(struct car_space carpark[CARPARK_ROWS]
[CARPARK_COLUMNS], int row, int col, int empty);
int check_carwash_sides(struct car_space carpark[CARPARK_ROWS]
[CARPARK_COLUMNS], int row, int col, int empty);
int is_carwash_nearby(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS],
 int licence_plate_no, int row, int col, int time_of_entry);
int no_spaces_left(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS],
 int licence_plate_no, int row, int col, int time_of_entry);

// Stage 4 functions:
void park_history(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS]);

////////////////////////////////////////////////////////////////////////////////
////////////////////// PROVIDED FUNCTION PROTOTYPE  ////////////////////////////
////////////////////////////////////////////////////////////////////////////////
void initialise_carpark(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS]);
void print_carpark(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS]);
void print_car_space(struct car_space space);


int main(void) {
    // Set up carpark. `carpark` is a 2D array of `struct car_space`s. 
    // It is `CARPARK_ROWS` x `CARPARK_COLUMNS` in size (which is 8 x 6 for this
    // assignment).
    struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS];

    // This will initialise all spaces in the carpark as NORMAL spaces which are 
    // all EMPTY.
    initialise_carpark(carpark);

    // TODO: Start writing code here!

    // TODO: Stage 1.1 - Carpark setup. Scan in which row of the carpark to be 
    // reserved for premium parking. The carpark should be printed once premium
    // parking is reserved. 
    printf("Welcome to CS Carpark!\n\n");
    printf("Which row of the carpark would you like to reserve for"
    " premium parking? ");
    premium_parking(carpark); 

    // TODO: Stage 1.2 - Scan in the initial cars.
    initial_cars(carpark);
    
    // Stage 1.3, 1.4, 1.5, 2.1, 2.2, 2.3, 2.4, 3.1, 3.2
    parking_commands(carpark);
}
    

////////////////////////////////////////////////////////////////////////////////
/////////////////////////////  YOUR FUNCTIONS //////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// TODO: Put your functions here

// Stage 1.1: Scans a number input between 0 - 7 and makes that row a premium
// parking row. 
void premium_parking(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS]) {
    int premium_park;

    // Scans in a number between 0 - 7
    scanf(" %d", &premium_park);

    // Checks if the number is within the valid range
    if (premium_park >= 0 && premium_park <= CARPARK_ROWS) {
        int i = 0;

        // Allocates the PREMIUM type to all columns in the certain row
        while (i < CARPARK_COLUMNS) {
            carpark[premium_park][i].type = PREMIUM;
            i++;
        }
        // Prints Carpark
        print_carpark(carpark);
    }
}

// Stage 1.2: Sets up initial cars by asking for the number of cars to be
// inputted and then parking each car into the carpark, storing the licence
// plate number, row, column. 
void initial_cars(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS]) {
    int num_cars, licence_plate_no, row, col;
    int i = 0;

    printf("Add all current cars to the carpark. How many cars would"
    " you like to add? ");
    scanf(" %d", &num_cars);
    printf("Where would you like to park each car?\n");

    // while i is smaller than the number of cars, keeps parking cars.
    while (i < num_cars) {
        scanf(" %04d %d %d", &licence_plate_no, &row, &col);

        // Checks if the (row, col) is out of bounds
        if (row >= CARPARK_ROWS || col >= CARPARK_COLUMNS) {
            printf("Invalid car space!\n");
        } else {
            carpark[row][col].licence_plate = licence_plate_no; 
            carpark[row][col].empty = 0;
        }
        i++;
    }
    // Prints the carpark
    print_carpark(carpark);
    printf("The carpark is now ready for business!\n");
}

// Stage 1.3: Holds all the carpark commands
void parking_commands(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS]) {
    char command;
    printf("Enter a command: ");

    // Scans a character in as a command, else stops program when 
    // the user presses 'CTRL + D'
    while (scanf(" %c", &command) == 1) {
        // Prints carpark if user enters 'P'
        if (command == PRINT_CARPARK) {
            print_carpark(carpark);
            // 1.4: Parks new cars if user enters 'p'
        } else if (command == NEW_PARKING) {
            new_parking(carpark);
            // 1.5: Prints the total occupancy of the carpark if
            // user enters 'o'
        } else if (command == TOTAL_PARKING) {
            count_total(carpark);
            // 2.1: Prints the free spaces remaining when user enters 'F'
        } else if (command == FREE_SPACES) {
            free_spaces(carpark);
            // 2.2 Applies a 10% discount to all spaces when user enters 'd'
        } else if (command == DISCOUNT) { 
            printf("A 10%% discount has been applied to all empty spaces!\n");
            discounts(carpark);
            // 2.3 Finds a car space a car is parked in when user enters 'f'
        } else if (command == FIND_CAR) { // 2.3
            find_car(carpark);
            // 2.4 Makes a inputted car leave when user enters 'l'
        } else if (command == LEAVE_CARPARK) { // 2.4
            leave_carpark(carpark);
            // 3.1 Builds an electric charging station when 'e' is entered
        } else if (command == CHARGE_STATION) { // 3.1
            charging_station(carpark);
            // 3.2 Charges an inputted car when 'c' is entered
        } else if (command == CHARGE_CAR) { // 3.2
            charge_car(carpark);
            // 3.3 Moves a car to another free space when 'm' is entered
        } else if (command == MOVE_CAR) { // 3.3
            move_car(carpark);
            // 3.4 Builds a carwash bay when 'w' is entered
        } else if (command == CARWASH_BUILD) { // 3.4
            carwash_bay(carpark);
            // 4.1 Prints the parking history of an car when 'h' is entered
        } else if (command == PARK_HISTORY) { // 4.1
            park_history(carpark);
        }
        printf("Enter a command: ");
    }
    printf("The carpark is now closed. Bye!\n");
}

// Stage 1.4, 1st function: Parks more cars into the carpark when the command
// 'p' is inputted
void new_parking(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS]) {
    int licence_plate_no, row, col, time_of_entry;

    // Scans the new licence plate, the (row, col) and the time of entry
    scanf("%04d %d %d %d", &licence_plate_no, &row, &col, 
    &time_of_entry);

    // Checks if the (row, col) is out of bounds
    if (row >= CARPARK_ROWS || col >= CARPARK_COLUMNS) {
        printf("Invalid car space!\n");

        // If the space isn't a Normal or Premium car space
    } else if ((carpark[row][col].type != NORMAL && 
    carpark[row][col].type != PREMIUM)
    || carpark[row][col].licence_plate != EMPTY) {

        // Checks if the space is an electric charging station
        if (carpark[row][col].licence_plate == ELECTRIC_CHARGING_STATION) {
            printf("Cannot park on a space occupied by an"
            " electric charging station.\n");

            // Checks if the space is a carwash bay
        } else if (carpark[row][col].type == CARWASH_BAY) {
            use_carwash(carpark, licence_plate_no, row, col, time_of_entry);

            // Checks if there's a car in the space
        } else {
            printf("Car space is already occupied!\n");
        }

        // If the space is a NORMAL or PREMIUM carspace
    }  else if (carpark[row][col].type == NORMAL || 
    carpark[row][col].type == PREMIUM) {
        park_new_car(carpark, licence_plate_no, row, col, time_of_entry);
    }        
}

// Stage 1.4, 2nd function: After confirming the space is empty and not a 
// special space, parks the car if it's not near a carwash bay
void park_new_car (struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS],
int licence_plate_no, int row, int col, int time_of_entry) {

    // Checks if the function returns 1 which means there's no carwash nearby
    if (is_carwash_nearby (carpark, licence_plate_no, row, col, 
    time_of_entry) == 1) { 
        // Parks the car in the empty space
        carpark[row][col].licence_plate = licence_plate_no;
        carpark[row][col].occupied_since = time_of_entry;
        printf("Car %04d was added into car space (%d, %d) at time %d!\n", 
        licence_plate_no, row, col, time_of_entry);
        carpark[row][col].empty = 0;

        // If the function returns 0
    } else if (is_carwash_nearby(carpark, licence_plate_no, row, 
    col, time_of_entry) == 0) {
        // Checks if there are no spaces which are empty and 
        // have no carwash bays next to them.
        if (no_spaces_left (carpark, licence_plate_no, row,
        col, time_of_entry) == 1) {
            carpark[row][col].licence_plate = licence_plate_no;
            carpark[row][col].occupied_since = time_of_entry;
            printf("Car %04d was added into car space (%d, %d) at time %d!\n", 
            licence_plate_no, row, col, time_of_entry);
            carpark[row][col].empty = 0;

        } else if (no_spaces_left(carpark, licence_plate_no, row,
        col, time_of_entry) == 0) {
            printf("Cannot park next to a carwash bay. There are still" 
            " other spaces available in the carpark.\n");
        }
    }
}

// Stage 1.5: Checks the total occupancy of the carpark and prints the number
// of cars parked and the number of empty spaces in the carpark.
void count_total(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS]) {
    int total_cars = 0; 
    int empty_space = 0;
    int i = 0;
    int j = 0;

    // Checks all the spaces
    for (i = 0; i < CARPARK_ROWS; i++) {
        for (j = 0; j < CARPARK_COLUMNS; j++) {
            // If the space is empty, add to the empty space counter
            if (carpark[i][j].licence_plate == EMPTY) {
                empty_space++;
                // Else add to the total cars parked counter. 
            } else {
                total_cars++;
            }
        }
    }

    // Prints the total cars and empty spaces
    printf("There are currently %d cars and %d empty car spaces in" 
    " the carpark.\n", total_cars, empty_space);
}

// Stage 2.1: Prints the free spaces in the carpark and their parking rate.
void free_spaces(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS]) {
    int row = 0, col = 0, empty_space = 0, pempty_space = 0;
    printf("The normal car spaces that are still available are:\n");

    // Checks through the carpark for NORMAL spaces
    for (row = 0; row < CARPARK_ROWS; row++) {
        for (col = 0; col < CARPARK_COLUMNS; col++) {
            // If the space is NORMAL and EMPTY, prints the (row, col)
            // of the space and its parking rate
            if (carpark[row][col].licence_plate == EMPTY && 
            carpark[row][col].type == NORMAL) {
                printf("(%d, %d): $%d\n", row, col, 
                carpark[row][col].parking_rate);
                carpark[row][col].empty = 1;
                // Else, adds to the empty space counter
            } else {
                empty_space++;
            }
        }
        // If all the normal spaces are empty, prints NONE
        if (empty_space == 42) {
            printf("NONE\n");
        }
    }
    printf("\nThe premium car spaces that are still available are:\n");

    // Does the same for PREMIUM spaces below
    for (row = 0; row < CARPARK_ROWS; row++) {
        for (col = 0; col < CARPARK_COLUMNS; col++) {

            if (carpark[row][col].licence_plate == EMPTY && 
            carpark[row][col].type == PREMIUM) {

                printf("(%d, %d): $%d\n", row, col, 
                carpark[row][col].p_parking_rate);
                carpark[row][col].empty = 1;

            } else if (carpark[row][col].licence_plate != EMPTY && 
            carpark[row][col].type == PREMIUM) {
                pempty_space++;
            }
        }
    }
    if (pempty_space == 6) {
        printf("NONE\n");
    }
    printf("\n");
}

// Stage 2.2: Applies a 10% discount to all empty spaces
void discounts(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS]) {
    int row = 0, col = 0;
    // Checks through all the carpark rows
    for (row = 0; row < CARPARK_ROWS; row++) {
        for (col = 0; col < CARPARK_COLUMNS; col++) {
            // If the space is EMPTY and is a NORMAL space, applies discount.
            if (carpark[row][col].licence_plate == EMPTY && 
            carpark[row][col].type == NORMAL) {
                carpark[row][col].parking_rate = 
                carpark[row][col].parking_rate * 0.9;
            }
        }
    }
    // Checks through all the carpark rows
    for (row = 0; row < CARPARK_ROWS; row++) {
        for (col = 0; col < CARPARK_COLUMNS; col++) {
            // If the space is EMPTY and is a PREMIUM space, applies 
            // discount to the premium parking rate.
            if (carpark[row][col].licence_plate == EMPTY && 
            carpark[row][col].type == PREMIUM) {
                carpark[row][col].p_parking_rate = 
                carpark[row][col].p_parking_rate * 0.9;
            }
        }
    }
}

// Stage 2.3: Looks for a car in the carpark and prints its location
void find_car(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS]) {
    int licence_plate_no;
    int row = 0, col = 0, nothing = 0;

    // Scans in the licence plate number
    scanf("%04d", &licence_plate_no);

    // Checks through all the carpark spaces
    for (row = 0; row < CARPARK_ROWS; row++) {
        for (col = 0; col < CARPARK_COLUMNS; col++) {

            // If the (row, col) has the number plate inputted, print location
            if (carpark[row][col].licence_plate == licence_plate_no) {
                printf("Car %04d is parked in car space (%d, %d).\n", 
                licence_plate_no, row, col);
                // Else, add to the 'nothing' counter
            } else {
                nothing++;
            }
        }
    }   
    // If all spaces are EMPTY, print that the licence plate isn't found
    if (nothing == 48) {
        printf("No car with licence plate number %04d could be found.\n"
        , licence_plate_no);
    }
}

// Stage 2.4, 1st function: Removes a car from the carpark and prints its 
// total time and hours parked in the carpark.
void leave_carpark(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS]) {
    int licence_plate_no, time_of_exit, total_time = 0;
    int row = 0, col = 0, nothing = 0;

    // Scans in the licence plate and time of exit
    scanf("%04d %d", &licence_plate_no, &time_of_exit);

    // Checks if the licence plate exists in the carpark
    for (row = 0; row < CARPARK_ROWS; row++) {
        for (col = 0; col < CARPARK_COLUMNS; col++) {
            // If the licence plate doesn't exist in the space, + 1 to nothing
            if (licence_plate_no != carpark[row][col].licence_plate) {
                nothing++;
            }
            // If all car spaces don't have the licence plate number
            if (nothing == 48) {
                printf("No car with licence plate number %04d could be found."
                "\n", licence_plate_no);
            }
        }
    }

    // Checks through the whole carpark
    for (row = 0; row < CARPARK_ROWS; row++) {
        for (col = 0; col < CARPARK_COLUMNS; col++) {
            // Checks if the time of exit is valid
            if (time_of_exit < carpark[row][col].occupied_since) {
                printf("The time of exit provided is invalid.\n");
                return;
                // Checks if it was parked after the carpark was initialised
            } else if (time_of_exit > carpark[row][col].occupied_since 
            && carpark[row][col].occupied_since > -1) {
                total_time = time_of_exit - carpark[row][col].occupied_since;
                leaving_specifics(carpark, total_time,
                 licence_plate_no, row, col);
                // Checks if the car was parked from initialisation 
            } else if (carpark[row][col].occupied_since == -1) {
                total_time = time_of_exit;
                leaving_specifics(carpark, total_time,
                licence_plate_no, row, col);
            } 
        }
    }
}

// Stage 2.4, 2nd function: If the car has passed all the valid checks,
// calculates total time and price and then removes car from carpark.
void leaving_specifics(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS],
int total_time, int licence_plate_no, int row, int col) {
    // If the car was parked in PREMIUM, calculates premium parking rate
    if (carpark[row][col].type == PREMIUM) {
        if (carpark[row][col].licence_plate == 2222) {
            carpark[row][col].total_price = (total_time * 
            carpark[row][col].p_parking_rate);
        } else {
            carpark[row][col].total_price = (total_time * 
            carpark[row][col].p_parking_rate) + carpark[row][col].total_price;
        }
        // If the car was parked in a NORMAL space, calculates normal parking rate
    } else if (carpark[row][col].type == NORMAL) {
        carpark[row][col].total_price = carpark[row][col].total_price + 
        carpark[row][col].parking_rate * total_time;
    } else {
        carpark[row][col].total_price = carpark[row][col].total_price;
    }

    // If the (row, col) contains the licence plate, the car can exit
    if (carpark[row][col].licence_plate == licence_plate_no) {

        // Prints message that car has left
        printf("Car %04d was parked for %d hours. The total price"
        " for this duration is $%d.\n", licence_plate_no, 
        carpark[row][col].total_time + total_time, 
        carpark[row][col].total_price);

        // Returns all the values of that particular (row, col) 
        // to its initial value
        carpark[row][col].licence_plate = EMPTY;
        carpark[row][col].parking_rate = NORMAL_PARKING_RATE;
        carpark[row][col].p_parking_rate = PREMIUM_PARKING_RATE;
        carpark[row][col].charging_rate = 0;
        carpark[row][col].occupied_since = -1;
        carpark[row][col].total_price = 0;
        carpark[row][col].total_time = 0;
        carpark[row][col].empty = 1;
    }
}

// Stage 3.1: Builds an electric charging station in the carpark
void charging_station(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS]) {
    int row, col, build_time, cable_length;

    // Scans in the (row, col), build time and cable length of the station
    scanf("%d %d %d %d", &row, &col, &build_time, &cable_length);

    // Adds values to that (row, col)
    carpark[row][col].type = ELECTRIC_CHARGING_STATION;
    carpark[row][col].occupied_since = build_time;
    carpark[row][col].licence_plate = ELECTRIC_CHARGING_STATION;
    carpark[row][col].cable_length = cable_length;
    carpark[row][col].empty = 3;

    // Prints that it has been built on that (row, col)
    printf("Electric charging station has been built on space (%d, "
    "%d) at time %d with cable length of %d.\n", row, col, build_time,
     cable_length);
}

// Stage 3.2, 1st function: Charges a car at a charging station
void charge_car(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS]) {
    int licence_plate_no, charge_from, charge_till, nothing = 0;
    int row = 0, col = 0;

    // Scans the licence plate of the car to be charged and 
    // its charging duration (charge from and charge till)
    scanf("%04d %d %d", &licence_plate_no, &charge_from, &charge_till);

    // Checks through the whole carpark
    for (row = 0; row < CARPARK_ROWS; row++) {
        for (col = 0; col < CARPARK_COLUMNS; col++) {

            // If the licence plate exists and isn't currently 
            // charging, find a charger
            if (carpark[row][col].licence_plate == licence_plate_no && 
            carpark[row][col].licence_plate != carpark[row][col].charging) {
                find_charger(carpark, row, col, charge_till, 
                charge_from, licence_plate_no);

                // Add to the 'nothing' counter
            } else {
                nothing++;
            } 
        }
    }
    // If no spaces have the licence plate, prints message
    if (nothing == 48) {
        printf("No car with licence plate number %04d could be found.\n"
        , licence_plate_no);
    }
}

// Stage 3.2, 2nd function: After checking the licence plate exists, finds a 
// charger to charge the car at. 
void find_charger(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS], 
int row, int col, int charge_till, int charge_from, int licence_plate_no) {
    int i = 0, j = 0;

    // Checks through all the spaces of the carpark
    for (i = 0; i < CARPARK_ROWS; i++) {
        for (j = 0; j < CARPARK_COLUMNS; j++) {

            // If the space is a station and isn't in use
            if ((carpark[i][j].licence_plate == ELECTRIC_CHARGING_STATION) 
            && carpark[i][j].licence_plate != ELEC_IN_USE) {
                cable_length(carpark, i, j, licence_plate_no, 
                charge_till, charge_from, row, col);

                // If the space is IN USE but ISN'T in use when
                // the new car wants to charge
            } else if ((carpark[i][j].licence_plate == ELEC_IN_USE) 
            && (charge_from >= carpark[i][j].leave_time)) {
                cable_length(carpark, i, j, licence_plate_no, 
                charge_till, charge_from, row, col);

                // If the space is IN USE but IS in use when
                // the new car wants to charge
            } else if ((carpark[i][j].licence_plate == ELEC_IN_USE) && 
            (charge_from < carpark[i][j].leave_time) 
            && (carpark[row][col].charging != IN_USE)) {
                shortest_time(carpark, i, j, licence_plate_no, 
                charge_till, charge_from, row, col);
                return;
            }
        } 
    } 
}

// Stage 3.2, 3rd function: After finding charger, checks if the cable 
// length is long enough
void cable_length(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS],
int i, int j, int licence_plate_no, int charge_till, int charge_from, int row,
int col) {
    // Create variable which stores the distance value 
    double distance = sqrt((i-row)*(i-row) + (j-col)*(j-col));

    // Checks if the cable length is bigger than the distance
    if (carpark[i][j].cable_length >= distance) {

        // If the station isn't in use and there isn't a closer charger
        if (carpark[row][col].charging != IN_USE && other_chargers (carpark, 
        row, col, licence_plate_no, charge_from, charge_till, distance) == 0) {

            // Print space is charging, assign to IN USE
            printf("Car %04d is being charged by the charging "
            "station located at (%d, %d).\n", licence_plate_no, i, j);

            carpark[i][j].licence_plate = ELEC_IN_USE;
            carpark[row][col].total_price = carpark[row][col].total_price + 
            (charge_till - charge_from) * 7;
            carpark[i][j].occupied_since = charge_from;
            carpark[i][j].leave_time = charge_till;
            carpark[row][col].charging = IN_USE;
            return;
        }

        // If cable less than distance, print that it's too far
    } else if (carpark[i][j].cable_length < distance) {
        printf("Too far away to be charged, move closer to a"
        " charging station.");
        return;
    }
}

// Stage 3.2, 4th function: Checks if there's more than 1 charger available 
// with a long enough distance
int other_chargers(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS], 
int row, int col, int licence_plate_no, int charge_from, int charge_till, 
double distance) {
    int k = 0, l = 0, yes = 0;

    // Checks the whole carpark
    for (k = 0; k < CARPARK_ROWS; k++) {
        for (l = 0; l < CARPARK_COLUMNS; l++) {

            // Checks if the space is an Electric Charging station, the 
            // distance is long enough and is currently not in use.
            if ((carpark[k][l].licence_plate == ELECTRIC_CHARGING_STATION) 
            && distance > sqrt((k-row)*(k-row) + (l-col)*(l-col)) && 
            (carpark[row][col].charging != IN_USE)) { 

                printf("Car %04d is being charged by the charging "
                "station located at (%d, %d).\n", licence_plate_no, k, l);

                // Adds values to the space
                carpark[k][l].licence_plate = ELEC_IN_USE;
                carpark[row][col].total_price = 
                carpark[row][col].total_price + 
                (charge_till - charge_from) * 7;
                carpark[k][l].occupied_since = charge_from;
                carpark[k][l].leave_time = charge_till;
                carpark[row][col].charging = IN_USE;

                yes = 1;
                return 1;
            }
        }
    }
    // Returns 1 if there is a closer space, returns 0 if there isn't
    if (yes == 1) {
        return 1;
    } else {
        return 0;
    }
} 

// Stage 3.2, 5th function: Checks which electric charger station has the 
// shortest time remaning until it finishes charging
void shortest_time(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS],
int i, int j, int licence_plate_no, int charge_till, int charge_from, int row,
int col) {
    int shortest_time = 100;
    int k = 0, l = 0, m = 0, n = 0, p = 0;

    // Checks through the whole carpark
    for (k = 0; k < CARPARK_ROWS; k++) {
        for (l = 0; l < CARPARK_COLUMNS; l++) {

            // Checks if the Electric charging station is in use and its 
            // finish time if smaller than the shortest time variable.
            if ((carpark[k][l].licence_plate == ELEC_IN_USE) && 
            (carpark[k][l].leave_time < shortest_time)) {
                // Assigns the finish time to the variable if shorter.
                shortest_time = carpark[k][l].leave_time;
                n = k;
                p = l;
                m++;
            }
        }
    }
    // After all the spaces have been checked, prints the (row, col) of 
    // the station with the smallest leave time.
    if (m > 0) {
        printf("All nearby charging stations are currently in use."
        " The next free charging station is (%d, %d), which will "
        "be free at time %d.\n", n, p, shortest_time);
    }
}

// Stage 3.3, 1st function: Moves a car from space to space
void move_car (struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS]) {
    int licence_plate_no, new_row = 0, new_col = 0, time_of_move, nothing = 0;
    int row = 0, col = 0;

    // Scans in the licence plate, new row and new column and time fo move
    scanf("%04d %d %d %d", &licence_plate_no, &new_row, &new_col
    , &time_of_move);

    // Checks if the new row and column are valid
    if (new_row >= CARPARK_ROWS || new_col >= CARPARK_COLUMNS) {
        printf("Car %04d cannot be moved to an invalid car space.\n"
        , licence_plate_no);
        return;
    } 

    // Checks the whole carpark
    for (row = 0; row < CARPARK_ROWS; row++) {
        for (col = 0; col < CARPARK_COLUMNS; col++) {
            // If the licence plate exists in the carpark
            if (carpark[row][col].licence_plate == licence_plate_no) {
                move_car_works(carpark, time_of_move, 
                new_row, new_col, row, col, licence_plate_no);
                return;
            } else {
                nothing++;
            }
        }
    }   
    // Prints the message if all spaces don't contain the licence number
    if (nothing == 48) {
        printf("No car with licence plate number %04d could be found.\n"
        , licence_plate_no);
    }
}

// Stage 3.3, 2nd function: After checking if the car exists in the carpark, 
// this function moves the car into the carspace
void move_car_works (struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS],
int time_of_move, int new_row, int new_col, int row, int col, 
int licence_plate_no) {
    // Checks if the move time is valid
    if (time_of_move <= carpark[row][col].occupied_since) {
        printf("The move time provided is invalid.\n");
        // Checks if there's another car already in the new space
    } else if (carpark[new_row][new_col].licence_plate != EMPTY) {
        printf("Car %04d could not be moved to space (%d, %d) as "
        "car %04d is already parked there.\n", licence_plate_no, 
        new_row, new_col, carpark[new_row][new_col].licence_plate);
        // Checks if the new space is a carwash bay and in use
    } else if (carpark[new_row][new_col].type == CARWASH_BAY && 
    carpark[row][col].charging != IN_USE) {

        // Does different price calculations depending on the previous space
        if (carpark[row][col].type == PREMIUM) {
            carpark[row][col].total_price = (time_of_move * 
            carpark[row][col].p_parking_rate) + carpark[row][col].total_price;
        } else if (carpark[row][col].type == NORMAL) {
            carpark[row][col].total_price = carpark[row][col].total_price + 
            carpark[row][col].parking_rate * time_of_move;
        }
        if (carpark[new_row][new_col].licence_plate == licence_plate_no) {
            carpark[row][col].licence_plate = EMPTY;
        }

        carpark[new_row][new_col].total_price = carpark[row][col].total_price;
        if (new_col == 5 && new_row == 6) {
            if (!(carpark[new_row + 1][new_col].type == CARWASH_BAY || 
            carpark[new_row + 1][new_col].licence_plate == EMPTY)) {
                printf("This carwash bay cannot be used as one or more of " 
                "the surrounding spaces are currently occupied. \n");
                return;
            }
        }

        use_carwash(carpark, licence_plate_no, new_row, new_col, time_of_move);
        carpark[row][col].licence_plate = EMPTY;
        carpark[row][col].total_time = time_of_move - 
        carpark[row][col].total_time;
        carpark[new_row][new_col].total_time = carpark[row][col].total_time;

        // If the new space is a PREMIUM or NORMAL empty space
    } else if (carpark[new_row][new_col].type == PREMIUM || 
    carpark[new_row][new_col].type == NORMAL) {
        car_moving_in(carpark, time_of_move, 
        new_row, new_col, row, col, licence_plate_no);
        
    }
}

// Stage 3.3, 3rd function: Checks if the new space has a carwash bay nearby
void car_moving_in(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS],
int time_of_move, int new_row, int new_col, int row, int col, 
int licence_plate_no) {
    // If there isn't a carwash bay nearby
    if (is_carwash_nearby(carpark, licence_plate_no, new_row, 
        new_col, time_of_move) == 1) {
        print_car_moved(carpark, time_of_move, 
        new_row, new_col, row, col, licence_plate_no);

        // If there is a carwash bay nearby
    } else if (is_carwash_nearby(carpark, licence_plate_no, new_row, 
    new_col, time_of_move) == 0) {

        // Checks if there's no spaces left with no carwash bays nearby
        if (no_spaces_left (carpark, licence_plate_no, new_row,
        new_col, time_of_move) == 1) {

            print_car_moved(carpark, time_of_move, 
            new_row, new_col, row, col, licence_plate_no);

            // If there is a carwash nearby, prints message
        } else if (no_spaces_left (carpark, licence_plate_no, new_row,
        new_col, time_of_move) == 0) {

            printf("Cannot park next to a carwash bay. There are still" 
            " other spaces available in the carpark.\n");

        }
    }
}

// Stage 3.3, 4th function: Prints the moved car in the new space
void print_car_moved(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS],
int time_of_move, int new_row, int new_col, int row, int col, 
int licence_plate_no) {

    printf("Car %04d has been moved to space (%d, %d).\n", 
    licence_plate_no, new_row, new_col);

    carpark[new_row][new_col].licence_plate = licence_plate_no;
    carpark[row][col].licence_plate = EMPTY;

    // If the car moved from a normal to a premium space
    if (carpark[new_row][new_col].type == PREMIUM && 
    carpark[row][col].type == NORMAL) {

        carpark[new_row][new_col].total_price = (time_of_move - 
        carpark[row][col].occupied_since) * 
        carpark[row][col].parking_rate;
        carpark[new_row][new_col].occupied_since = time_of_move;
        carpark[new_row][new_col].total_time = time_of_move 
        - carpark[row][col].occupied_since;

        // If the car moved from a premium space to a normal space
    } else if (carpark[new_row][new_col].type == NORMAL && 
    carpark[row][col].type == PREMIUM) {

        carpark[new_row][new_col].total_price = (time_of_move - 
        carpark[row][col].occupied_since) * 
        carpark[row][col].p_parking_rate;
        carpark[new_row][new_col].occupied_since = time_of_move;
        carpark[new_row][new_col].total_time = time_of_move 
        - carpark[row][col].occupied_since;

    } else {
        carpark[new_row][new_col].total_price = 
        carpark[new_row][new_col].total_price;
    }
}


// Stage 3.4, 1st function: Builds a carwash bay
void carwash_bay(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS]) {
    int row = 0, col = 0, build_time, stop = 0;
    int empty = 0;

    // Scans in the (row, col) and the build time
    scanf("%d %d %d", &row, &col, &build_time);

    // Checks if the (row, col) is in the corner of the carpark
    if ((row == 0 && col == 0) || (row == 0 && col == 5) || 
    (row == 7 && col == 0) || (row == 7 && col == 5)) {

        if (check_carwash_corners(carpark, row, col, empty) == 1) {
            empty = 1;
        } else if (check_carwash_corners(carpark, row, col, empty) == 0) {
            printf("This carwash bay cannot be built as one or " 
            "more of the surrounding spaces are currently occupied.\n");
            stop = 2; empty = 0;
        }
    }
    // Checks if the (row, col) is on the sides of the carpark
    if ((row == 0 || row == 7 || col == 0 || col == 5) && 
    (check_carwash_corners(carpark, row, col, empty) == 0) && (stop != 2)) {

        if (check_carwash_sides(carpark, row, col, empty) == 1) {
            empty = 1;

        } else if (check_carwash_sides(carpark, row, col, empty) == 0) {
            printf("This carwash bay cannot be built as one or " 
            "more of the surrounding spaces are currently occupied.\n");
            stop = 3; empty = 0;
        }

        // Checks if the surrounding spaces are occupied or not
    } else if ((check_carwash_corners(carpark, row, col, empty) == 0) && 
    (stop != 2) && (check_carwash_corners(carpark, row, col, empty) == 0) 
    && (stop != 3)) {
        empty = surroundings_of_bay(carpark, row, col, empty);
    }
    // If all checks have been passed, builds carwash bay
    if (empty == 1) {
        printf("Carwash bay has been built on space (%d, %d) at time %d.\n"
        , row, col, build_time);
        carpark[row][col].type = CARWASH_BAY; 
        carpark[row][col].occupied_since = build_time;
        carpark[row][col].empty = 2;
    }

}

// 3.4, 2nd function: Checks the surroundings of the space
int surroundings_of_bay(struct car_space carpark[CARPARK_ROWS]
[CARPARK_COLUMNS], int row, int col, int empty) {
    int i = row-1, j = col-1, reset_col = j;
    // Checks the 8 spaces surrounding the (row, col)
    while (i <= row + 1) {
        j = reset_col;

        while (j <= col + 1) {

            // Checks if the space is a Carwash bay and is empty
            if (carpark[i][j].type == CARWASH_BAY || 
            carpark[i][j].licence_plate == EMPTY) {
                empty = 1;

            } else if (carpark[i][j].licence_plate != EMPTY) {
                printf("This carwash bay cannot be built as one or more " 
                "of the surrounding spaces are currently occupied.\n");
                empty = 0;
                return 0; 
            }
            j++;
        }
        i++;
    }
    if (empty == 1) {
        return 1;
    } else {
        return 0;
    }
}

// 3.4, 3rd function: Checks the corners of the carpark
int check_carwash_corners(struct car_space carpark[CARPARK_ROWS]
[CARPARK_COLUMNS], int row, int col, int empty) {
    // Checks each specific (row, col) corner to see if the surroundings are empty
    if (row == 0 && col == 0) {
        // Checks if all 3 surrounding spaces are empty and not a carwash bay
        if ((carpark[row + 1][col + 1].type == CARWASH_BAY || carpark[row + 1]
        [col + 1].licence_plate == EMPTY) && (carpark[row + 1][col].type == 
        CARWASH_BAY || carpark[row + 1][col].licence_plate == EMPTY) && 
        (carpark[row][col + 1].type == CARWASH_BAY || carpark[row][col + 1].
        licence_plate == EMPTY)) {
            empty = 1;
        }        

    } else if (row == 0 && col == 5) {
        // Checks if all 3 surrounding spaces are empty and not a carwash bay
        if ((carpark[row + 1][col].type == CARWASH_BAY || carpark[row + 1]
        [col].licence_plate == EMPTY) && (carpark[row + 1][col - 1].type 
        == CARWASH_BAY || carpark[row + 1][col - 1].licence_plate == EMPTY) 
        && (carpark[row][col - 1].type == CARWASH_BAY || 
        carpark[row][col - 1].licence_plate == EMPTY)) {
            empty = 1;
        }      

    } else if (row == 7 && col == 0) {
        // Checks if all 3 surrounding spaces are empty and not a carwash bay
        if ((carpark[row][col + 1].type == CARWASH_BAY || carpark[row]
        [col + 1].licence_plate == EMPTY) && (carpark[row - 1][col].type == 
        CARWASH_BAY || carpark[row - 1][col].licence_plate == EMPTY) && 
        (carpark[row - 1][col + 1].type == CARWASH_BAY || carpark[row - 1]
        [col + 1].licence_plate == EMPTY)) {
            empty = 1;
        }    

    } else if (row == 7 && col == 5) {
        // Checks if all 3 surrounding spaces are empty and not a carwash bay
        if ((carpark[row - 1][col - 1].type == CARWASH_BAY || 
        carpark[row - 1][col - 1].licence_plate == EMPTY) && 
        (carpark[row - 1][col].type == CARWASH_BAY || 
        carpark[row - 1][col].licence_plate == EMPTY) && 
        (carpark[row][col - 1].type == CARWASH_BAY || 
        carpark[row][col - 1].licence_plate == EMPTY)) {
            empty = 1;
        }                
    }
    if (empty == 1) {
        return empty;
    } else {
        return 0;
    }
}

// 3.4, 4th function: Checks the sides of the carpark
int check_carwash_sides(struct car_space carpark[CARPARK_ROWS]
[CARPARK_COLUMNS], int row, int col, int empty) {
    empty = 0;
    // Checks the rows on the border of the carpark
    if ((row == 0 && col != 0) || (row == 7 && col != 0) || 
    (row == 0 && col != 5) || (row == 7 && col != 5)) {
        int j = col - 1;

        while (j <= col + 1) {
            // Checks if surrounding spaces are empty and not a carwash bay
            if (carpark[row][j].type == CARWASH_BAY || 
            carpark[row][j].licence_plate == EMPTY) {
                empty = 1;
            }
            j++;
        }
        // Checks the columns on the border of the carpark
    } else if ((col == 0 && row != 0) || (col == 5 && row != 0) || 
    (col == 0 && row != 7) || (col == 5 && row != 7)) {
        int i = row - 1;

        while (i <= row + 1) {
            // Checks if surrounding spaces are empty and not a carwash bay
            if (carpark[i][col].type == CARWASH_BAY || 
            carpark[i][col].licence_plate == EMPTY) {
                empty = 1;
            }
            i++;
        }

    } else {
        return 0;
    }              
    if (empty == 1) {
        return empty;
    } else {
        return 0;
    }
}


// 3.4, 5th function: Parks car in the carwash bay
void use_carwash(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS],
int licence_plate_no, int row, int col, int time_of_entry) {
    int empty = 0;
    // Checks if the (row, col) is located on the border
    if (row == 0 || row == 7 || col == 0 || col == 5) {
        check_carwash_sides(carpark, row, col, empty);

        if (check_carwash_sides(carpark, row, col, empty) == 1) {
            empty = 1;

        } else if (check_carwash_sides(carpark, row, col, empty) == 0) {
            printf("This carwash bay cannot be used as one or more of" 
            "the surrounding spaces are currently occupied. \n");
            return;
        }
        // Check the surroundings of the bay to be used
    } else {
        empty = use_surroundings(carpark, row, col, empty);
    }
    // If the conditions are passed, the car is moved into the carwash bay
    if (empty == 1) {
        printf("Car %04d is now using the carwash bay located at (%d, %d).\n"
        , licence_plate_no, row, col);
        carpark[row][col].licence_plate = licence_plate_no;
        carpark[row][col].occupied_since = time_of_entry;
        carpark[row][col].charging = IN_USE; 
        carpark[row][col].total_price = carpark[row][col].total_price + CARWASH_RATE;
    }
}

// 3.4, 6th function: Checks the surroundings of a carwash bay before use
int use_surroundings(struct car_space carpark[CARPARK_ROWS]
[CARPARK_COLUMNS], int row, int col, int empty) {
    int i = row-1, j = col-1, reset_col = j;
    // Checks the 8 spaces surrounding the (row, col)
    while (i <= row + 1) {
        j = reset_col;

        while (j <= col + 1) {

            // Checks if the space is a Carwash bay and is empty
            if (carpark[i][j].type == CARWASH_BAY || 
            carpark[i][j].licence_plate == EMPTY) {
                empty = 1;

            } else if (carpark[i][j].licence_plate != EMPTY) {
                printf("This carwash bay cannot be used as one or more of" 
                "the surrounding spaces are currently occupied. \n");
                empty = 0;
                return 0; 
            }
            j++;
        }
        i++;
    }
    if (empty == 1) {
        return 1;
    } else {
        return 0;
    }
}

// 3.4, 7th function: Checks if there's a carwash near the space
int is_carwash_nearby (struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS],
int licence_plate_no, int row, int col, int time_of_entry) {

    int i = row-1, j = col-1, reset_col = j, empty = 1;

    // Makes sure that the row and column are within the bounds of the carpark
    while ((i <= row + 1) && (i < 8) && (i > 0)) {
        while ((j <= col + 1) && (j < 6) && (j > 0)) {
            // If space isn't a carwash bay and is empty
            if (carpark[i][j].licence_plate == EMPTY && carpark[i][j].type 
            != CARWASH_BAY) {
                empty = 1;
                // If space is a carwash bay
            } else if (carpark[i][j].type == CARWASH_BAY) {
                empty = 0; 
                return 0;
                // If space isn't empty
            } else if (carpark[i][j].licence_plate != EMPTY) {
                empty = 1;
            }
            j++;
        }
        j = reset_col;
        i++;
    } 
    if (empty == 1) {
        return 1;
    } else {
        return 0;
    }

}

// 3.4, 8th function: Checks if there's no spaces left with no carwash bay
// in its surroundings
int no_spaces_left (struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS],
int licence_plate_no, int row, int col, int time_of_entry) {
    int i = 0, j = 0, empty = 0;

    // Checks the corners of the carpark
    if (check_carwash_corners(carpark, row, col, time_of_entry) == 1) {
        return 1;
    }

    // CHecks all the rows and columns of the carpark
    while (i < CARPARK_ROWS) {
        j = 0;
        while (j < CARPARK_COLUMNS) {
            // If the carspace is empty, isn't a carwash bay and 
            // has a carwash bay nearby
            if ((carpark[i][j].licence_plate == EMPTY && carpark[i][j].type 
            != CARWASH_BAY) && is_carwash_nearby(carpark, licence_plate_no, row, 
            col, time_of_entry) == 0) {
                empty = 0;
                // If the space is a carwash bay
            } else if (carpark[i][j].type == CARWASH_BAY) {
                empty = 0;   
            } else {
                empty = 1;
            }
            j++;
        }
        i++;
    }
    if (empty == 1) {
        return 1;
    } else {
        return 0;
    }
}


// Stage 4.1: Checks the parking history of a car
void park_history(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS]) {

}


///////////////////////////////////////////////////////////////////////////////
/////////////////////////// PROVIDED FUNCTIONS  ///////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/**
 * Initialises carpark spaces as NORMAL spaces with NORMAL_PARKING_RATE that are
 * initially EMPTY.
 * 
 * Parameters:
 *     carpark - The carpark to initialise.
 * Returns:
 *     Nothing.
 */
void initialise_carpark(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS]) {
    for (int row = 0; row < CARPARK_ROWS; row++) {
        for (int col = 0; col < CARPARK_COLUMNS; col++) {
            carpark[row][col].type = NORMAL;
            carpark[row][col].parking_rate = NORMAL_PARKING_RATE;
            carpark[row][col].p_parking_rate = PREMIUM_PARKING_RATE;
            carpark[row][col].licence_plate = EMPTY;
            carpark[row][col].occupied_since = 0;
            carpark[row][col].leave_time = 0;
            carpark[row][col].cable_length = EMPTY;
            carpark[row][col].charging_rate = 0;
            carpark[row][col].charging = EMPTY;
            carpark[row][col].total_price = 0;
            carpark[row][col].total_time = 0;
            carpark[row][col].empty = 1;
        }
    }
}

/**
 * Prints all carpark spaces, displaying their type and the licence plate of 
 * any cars parked in the carpark.
 * 
 * Parameters:
 *     carpark   - The carpark to be printed
 * Returns:
 *     Nothing.
 */
void print_carpark(struct car_space carpark[CARPARK_ROWS][CARPARK_COLUMNS]) {
    printf("-------------------------------------------------------------------\n");
    for (int row = 0; row < CARPARK_ROWS; row++) {
        for (int col = 0; col < CARPARK_COLUMNS; col++) {
            print_car_space(carpark[row][col]);
        }
        printf("|\n");
        printf("-------------------------------------------------------------------\n");
    }
    printf("\n");
}

/**
 * Prints the type of a particular car space, as well as the licence plate of 
 * the car located at that car space.
 * 
 * Parameters:
 *     car_space         - The car space to print.
 *
 * Returns:
 *     Nothing.
 */
void print_car_space(struct car_space car_space) {
    printf("|");
    if (car_space.type == NORMAL) {
        printf(" N :");
    } else if (car_space.type  == PREMIUM) {
        printf(" P :");
    } else if (car_space.type  == CARWASH_BAY) {
        printf(" W :");
    } else if (car_space.type  == ELECTRIC_CHARGING_STATION) {
        printf(" CHARGER  ");
    }
    if (car_space.type != ELECTRIC_CHARGING_STATION) {
        if (car_space.licence_plate == EMPTY) {
            printf("      ");
        } else {
            printf(" %04d ", car_space.licence_plate);
        }
    }
    
}
