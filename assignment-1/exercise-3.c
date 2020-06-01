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
