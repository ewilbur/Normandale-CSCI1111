/*
 * @program exercise-4.c
 * @author Evan Wilbur
 * @course CSCI 1111
 * @semester Summer 2020
 * @description Answer for exercise 4 which prints out the same string 3 times
 *              and then finishes the jingle.
 */
#include <stdio.h>

int main(void) {
    int i = 0;
    for (; i < 3 || (!printf("Which nobody can deny!\n")); ++i, printf("For he's a jolly good fellow!\n"))
        ;
   printf("Press any character to continue");
   getchar();
   return 0;
}
