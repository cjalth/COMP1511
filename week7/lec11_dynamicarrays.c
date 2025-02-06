#include <stdio.h>
#include <stdlib.h>

#define NAME_MAX_LEN 100
#define MAX_PARTY 6

enum element { WATER, FIRE, FLYING, GRASS };

struct pokemon {
    int id;
    char name[NAME_MAX_LEN]; 
    int hp;
    double attack_power;
    enum element type;
}; 

struct pokedex {
    struct pokemon *found;
    int number_found;

};

struct game_data {
    struct pokedex player_pokedex;
    struct pokemon party[MAX_PARTY];

};

struct game_data void initialise_game(void) {
    struct game_data game;

    game.player_pokedex.number_found = 0;
    game.player_pokedex.found = NULL;

    return game;
};

void add_to_pokedex(struct game_data *game, struct pokemon wild_pokemon) {
    // assigns to num after updated (which is + 1)
    int num = ++game->player_pokedex.number_found;
    game->player_pokedex.found = 
        realloc(game->player_pkedex.found, num * sizeof(struct pokemon));
    game->player_pokedex.found[num - 1] = wild_pokemon;
}

void print_pokedex(struct pokedex *pokedex) {
    if(pokedex->number_found == 0) {
        printf("Oh no... you are yet to start your adventure...\n");
    }
    for(int i = 0; i < pokedex->number_found; i++) {
        fputs(pokedex->found[i].name, stdout); //remember that [i] dereferences
        printf(" | ");
    }
}

void encounter_wild_pokemon(struct game_data *game) {
    // find a wild pokemon
    struct pokemon wild_pokemon = {.id = 0, .name = "Bulbasaur", 
    .hp = 50, .attack_power = 0.5, .type = GRASS};

    // check thast it exists in the pokedex
    int already_encountered= 0;
    for (int i = 0; i < game->player_pokedex.number_found; i++) {
        if (game->player_pokedex.found[i].id == wild_pokemen.id) {
            already_encountered = 1;
        }
    }

    // if not, add it
    // 1 is true, and 0 is false
    if (!already_encountered) {
        add_to_pokedex(game, wild_pokemon);
    }

    // else don't
    // give player a chance to catch it


};

int main(void) {

    struct game_data game = initialise_game();
    print_pokedex(&game.player_pokedex);

    encounter_wild_pokemon(&game);

    print_pokedex(&game.player_pokedex);

    return 0;
}