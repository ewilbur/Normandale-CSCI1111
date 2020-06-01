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
   printf("You are %u days old\n", years_to_days(user_years));
   return 0;
}

unsigned int years_to_days(unsigned int years) {
    return years * DAYS_PER_YEAR;
}
