#include <stdio.h>

int main(void) {
    int row = 0;
    
// nested loops are while's in while's
    while(row < 5) {
        int col = 0;
        while(col < row+1){
            printf("%d ", col+1);
            col = col + 1;
        }
        printf("\n");
        row = row + 1;
    }

    return 0;

}