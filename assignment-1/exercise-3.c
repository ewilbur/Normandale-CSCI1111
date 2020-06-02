/*
 * @program exercise-3.c
 * @author Evan Wilbur
 * @course CSCI 1111
 * @semester Summer 2020
 * @description This program takes in a number of years and returns the number
 *              of days. Ignores leap years and fractional years.
 */
#include <stdio.h>

#define DAYS_PER_YEAR 365

unsigned int years_to_days(unsigned int);

int main (void) {
   unsigned int user_years;
   printf("Enter an age in years: ");
   scanf("%u", &user_years);
   getchar(); /* Read in the newline that is still in the buffer */
   printf("You are %u days old\n", years_to_days(user_years));

   printf("Press any character to continue");
   getchar();
   return 0;
}

unsigned int years_to_days(unsigned int years) {
    return years * DAYS_PER_YEAR;
}
