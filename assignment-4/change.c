/*
 * @author Evan Wilbur
 * @class CSCI 1111
 * @section 10
 * @description  A simple calculator to find the change. No really anything
 *               too special here. I really just slapped this together to
 *               complete the project. There are many rooms for improvement
 */


#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
    unsigned pennies;
    unsigned nickles;
    unsigned dimes;
    unsigned quarters;
    unsigned dollars;
    unsigned fivers;
    unsigned tenners;
    unsigned twenties;
} change;

void clear_change(change*);
void print_change(change*);
void flush_buffer();
void make_change(unsigned, change*);
unsigned dollar_amount_to_cents(float dollar_amount);


int main() {
    float user_paid = 0.;
    float user_owes = 0.;
    unsigned paid_owes_difference = 0;
    change user_change;
    clear_change(&user_change);
    int i = 0;

    do {
        printf("Enter the amount you owe: ");
        i = scanf("%f", &user_owes);
        if (i <= 0) printf("Invalid input!\n");
        flush_buffer();
    } while (i <= 0);

    do {
        printf("Enter the amount you paid: ");
        i = scanf("%f", &user_paid);
        if (i <= 0) printf("Invalid input!\n");
        flush_buffer();
    } while (i <= 0);

    paid_owes_difference = dollar_amount_to_cents(user_paid) - dollar_amount_to_cents(user_owes);

    make_change( paid_owes_difference,
                &user_change);
    print_change(&user_change);

    printf("Press 'q' to quit or any other key to go again: ");
    if (getchar() == 'q') return 0;
    else                  return main();
}

void clear_change(change *chng) {
    if (chng == NULL) return;
    memset(chng, 0, sizeof(change));
}

void print_change(change *chng) {
    if (chng == NULL) return;
    printf("pennies = %u\n" , chng->pennies); 
    printf("nickles = %u\n" , chng->nickles); 
    printf("dimes = %u\n"   , chng->dimes); 
    printf("quarters = %u\n", chng->quarters); 
    printf("dollars = %u\n" , chng->dollars); 
    printf("fives = %u\n"   , chng->fivers); 
    printf("tens = %u\n"    , chng->tenners); 
    printf("twenties = %u\n", chng->twenties); 
}

void flush_buffer() {
    while (getchar() != '\n');
}

void make_change(unsigned paid_difference, change *user_change) {
    if (user_change == NULL) return;
    user_change->twenties = paid_difference / 2000;
    paid_difference %= 2000;
    user_change->tenners = paid_difference / 1000;
    paid_difference %= 1000;
    user_change->fivers = paid_difference / 500;
    paid_difference %= 500;
    user_change->dollars = paid_difference / 100;
    paid_difference %= 100;
    user_change->quarters = paid_difference / 25;
    paid_difference %= 25;
    user_change->dimes = paid_difference / 10;
    paid_difference %= 10;
    user_change->nickles = paid_difference / 5;
    paid_difference %= 5;
    user_change->pennies = paid_difference / 1;
    paid_difference %= 1;
}

unsigned dollar_amount_to_cents(float dollar_amount) {
    dollar_amount *= 100.0;
    return (unsigned)floor((double)dollar_amount);
}
