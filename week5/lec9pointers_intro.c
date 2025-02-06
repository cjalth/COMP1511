#include <stdio.h>

int main(void) {
    // a normal int variable
    int my_integer = 5;
    int my_second_integer = 15;

    // a pointer to an int
    int *pointer_to_my_int = &my_integer;

    // print the pointer (memory address) stored in pointer_to_my_int
    printf("%p\n", pointer_to_my_int);

    // print the memory address of my_integer
    printf("%p\n", &my_integer);

    // dereference pointer_to_my_int to the actual value
    printf("%d\n", *pointer_to_my_int);

    // change value of pointer_to_my_int
    *pointer_to_my_int = 10;
    printf("%d\n", *pointer_to_my_int);
    
    return 0;

}