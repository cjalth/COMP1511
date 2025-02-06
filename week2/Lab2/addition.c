// Addition
// addition.c
//
// This program was writen by Caitlin Wong (z5477471)
// on 08/06/2023
//
// This program adds the number of tutors and students inputted

#include <stdio.h>

int main(void) {
    int tutors;
    int students;
    printf("Please enter the number of students and tutors: ");
    scanf("%d %d", &students, &tutors);
    printf("%d + %d = %d\n", students, tutors, students + tutors);

    return 0;
}