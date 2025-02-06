#include <stdio.h>

// A simple function which accepts two integers (num_1, num_2),
// and returns the result (int) of adding them.

int add_two_positive_integers(int num_1, int num_2);
double add_doubles(int x, double y);

int add_two_positive_integers(int num_1, int num_2) {
    add_doubles(2,4);
    if(num_1 > 0 && num_2 >0 ){
        return num_1 + num_2;
    }
    return -1;
}

double add_doubles(int x, double y) {


}

int main(void) {
    int sum = add_two_positive_integers(add_doubles(2.6,3.6),50);
    int sum_2 = add_two_positive_integers(-30,50);
    int sum_3 = 4.5

    printf("%d %d\n",sum, sum_2);

    return 0;
}