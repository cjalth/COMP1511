#include <stdio.h>

int main(void) {

    double weight_lifted = 50.5;
    int num_reps = 4;

    // it follows BODMAS
    double total_weight_lifted;
    total_weight_lifted = weight_lifted * num_reps;

    printf("%lf\n", total_weight_lifted);

    return 0;

}