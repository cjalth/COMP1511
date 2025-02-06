#include <stdio.h>

struct animal {
    int cuteness;
    int safety;
    double price;
};


int main(void){
    struct animal dog_1;
    struct animal otter_1;

    dog_1.cuteness = 500;
    otter_1.cuteness = 3200;

    dog_1.safety = 10;
    otter_1.safety = 100;

    dog_1.price = 2000;
    otter_1.price = 0.5;

    printf("cuteness: %d\n", dog_1.cuteness);
    printf("safety: %d\n", dog_1.safety);
    printf("price: %lf\n", dog_1.price);
    printf("safety: %d\n", otter_1.safety);

    return 0;
}