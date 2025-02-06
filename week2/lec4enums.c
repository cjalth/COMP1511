#include <stdio.h>

enum species { Dog=2, Pikachu=3, Otter=0, PufferFish=1, Dragon, Termite, Anteater, Kangaroo };

int main (void) {
    enum species my_species = PufferFish;

    printf("%d\n", my_species);

    return 0;

}