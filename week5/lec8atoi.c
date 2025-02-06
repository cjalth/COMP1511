#include <stdio.h>

int main(void) {
char input[MAX_STR];

//read into the string
printf("Enter your age");
fgets(input, MAX_STR, stdin);

//takes a string, converts it to an integer
int age = atoi(input);

print("%d\n", age + 5);

return 0;
}