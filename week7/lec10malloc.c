#include <stdio.h>
#include <stdlib.h>

void populate_heights(double *heights, int size) {
    for(int i = 0; i < size; i++) {
        printf("Enter in the height: ");
        scanf("%lf", &heights[i]); // heights is an address. [i] address_loc + i * sizeof(ptr)
    }
}

void print_heights(double *heights, int size) {
    for(int i = 0; i < size; i++) {
        printf("User is %lf tall\n", heights[i]);
    }
}

double *create_heights_array(int num_elements) {
    return malloc(num_elements * sizeof(double));
}

int main(void) {

    int num_elements;
    printf("Enter the number of heights: ");
    scanf("%d", &num_elements);

    double *heights = create_heights_array(num_elements);

    populate_heights(heights, num_elements);
    print_heights(heights, num_elements);
    

    printf("%lf\n", heights[0]);
    printf("%p\n", heights);

    return 0;
}