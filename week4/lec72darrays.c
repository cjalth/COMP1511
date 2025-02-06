#include <stdio.h>
#define MAX_COLS 16
#define MAX_ROWS 16
#define MAX_WORD_LENGTH 5

void print_crossword(char crossword[MAX_ROWS][MAX_COLS]);
void initialise_crossword(char crossword[MAX_ROWS][MAX_COLS]);

void can_insert_word(char crossword[MAX_ROWS][MAX_COLS], char word[MAX_WORD_LENGTH], 
                 int row_to_place, int col_to_place) {
    // start at row_to_place, col_to_place and loop across the row adding each letter
    int word_len = strlen(word);

    if (row_to_place < 0 || col_to_place < 0) {
        return;
    }
    if (MAX_COLS - col_to_place < word_len) {
        return;
    } 
    return 1;

}

void insert_word(char crossword[MAX_ROWS][MAX_COLS], char word[MAX_WORD_LENGTH], 
                 int row_to_place, int col_to_place) {
    // start at row_to_place, col_to_place and loop across the row adding each letter
    if (can_insert_word(crossword, word, row_to_place, col_to_place)){
    //let's add it... 
    int i = 0;
    int j = 0;
    while (word[i] != '\0') {
        crossword[row_to_place][col_to_place + i] = word[i + j];
        if (direction == VERTICAL) {
        i++;
        } else {
        j++;
        }
    } 
    }
}


void initialise_crossword(char crossword[MAX_ROWS][MAX_COLS]) {
    int row = 0;
    while(row < MAX_ROWS) {
        int col = 0;
        while(col < MAX_COLS) {
            // at this point, we have row,col - an element
            crossword[row][col] = '.';
            col++;
        }
        row++;
    }

}

void print_crossword(char crossword[MAX_ROWS][MAX_COLS]) {
    int row = 0;
    while(row < MAX_ROWS) {
        int col = 0;
        while(col < MAX_COLS) {
            // at this point, we have row,col - an element
            printf("%c ", crossword[row][col]);
            col++;
        }
        printf("\n");
        row++;
    }

}

int main(void){
    char crossword[MAX_ROWS][MAX_COLS] = {};

    initialise_crossword(crossword);
    insert_word(crossword, "cat", 1, 1);
    insert_word(crossword, "xavier", 3, 0);
    print_crossword(crossword);

    return 0;

}