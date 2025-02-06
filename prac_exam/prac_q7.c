#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int number[10000];
    int len = 0;

    while (scanf("%d", &number[len]) == 1 && number[len] != 0) {
        len++;
    }

    int i = 0;
    while (i < len) {
        printf("%d", number[i]);
        i = i + 2;
    }

    i = 1;
    while (i < len) {
        printf("%d", number[i]);
        i = i + 2;
    }
    printf("\n");

    return 0;
}
