// Using struct arrays to store points of a shape
// points.c
//
// This program was writen by Caitlin Wong (z5477471)
// on 21/06/2023
//
// This program scans in the number of points that a shape 
// has and the coordinates of each point and then 
// prints the points given in order.

#include <stdio.h>

#define MAX_POINTS 10

struct point {
    // TODO: fill this in so that the struct can hold a point number and an 
    // x and y position
    //
    // i.e. This struct should contain:
    //      the point number (int), 
    //      and the x-coordinat and y-coordinate (doubles).
    int point_no;
    double x;
    double y;
};


// Prints a point out.
void print_point(int point_no, double x, double y);

int main(void) {

    // TODO: Declare an array of points of size MAX_POINTS
    struct point thepoints[MAX_POINTS] = {0};
    int point_no;
    printf("How many points in the shape? ");
    // TODO: scan in number of points in the shape
    scanf("%d", &point_no);

    printf("Enter points:\n");
    // TODO: scan in the details of each point into the array
    int i = 0;
    while (i < point_no) {
        double x;
        double y;
        scanf("%lf %lf", &x, &y);

        thepoints[i].x = x;
        thepoints[i].y = y;
        i++;

    }
    printf("\nShape Points:\n");
    // TODO: print all the points
    i = 0;
    while (i < point_no) {
        print_point(i + 1, thepoints[i].x, thepoints[i].y);
        i++;
    }


    return 0;
}


//  Prints a single point in the correct format.
//
// Parameters:
// - `point_no` -- The point number
// - `x`        -- The x-coordinate of the point
// - `y`        -- The y-coordinate of the point
//
// Returns: nothing.
void print_point(int point_no, double x, double y) {
    
    printf("%2d: x = %.3lf, y = %.3lf\n", point_no, x, y);
}