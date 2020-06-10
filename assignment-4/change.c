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
#include <stdlib.h>

#define TENDER_STRING_LENGTH 32
static const char SINGULAR_TENDER_NAMES[][TENDER_STRING_LENGTH]
    = { "penny",
        "nickel",
        "dime", 
        "quarter",
        "dollar",
        "five dollar",
        "ten dollar",
        "twenty dollar",
        "fifty dollar",
        "hundered dollar" };

static const char PLURAL_TENDER_NAMES[][TENDER_STRING_LENGTH]
    = { "pennies",
        "nickels",
        "dimes",
        "quarters",
        "dollars",
        "five dollars",
        "ten dollars",
        "twenty dollars",
        "fifty dollars",
        "hundred dollars" };


static const int TENDER_VALUES[]
    = { 1,
        5,
        10,
        25,
        100,
        500,
        1000,
        2000 };

#define NUM_TENDER (sizeof(TENDER_VALUES) / sizeof(int))

typedef struct {
    int tender_values[NUM_TENDER];
    int num_tender[NUM_TENDER];
} Tender;

void printchange(Tender *);
void mkchange(Tender *, int);
void flush_buffer();
Tender *mktender();
void freetender(Tender *);
int currency_to_cents(float);

int main() {
    float amount_paid = 0;
    float amount_owed = 0;

    int amount_paid_cent = 0;
    int amount_owed_cent = 0;
    int amount_in_change = 0;

    int read_word_count = 0;

    Tender *tender = mktender();

    do {
        printf("Enter the amount you owe: ");
        read_word_count = scanf("%f", &amount_owed);
        if (read_word_count <= 0) {
            fprintf(stderr, "Invalid amount entered\n");
            flush_buffer();
        }
        amount_owed_cent = currency_to_cents(amount_owed);
    } while (read_word_count <= 0);

    do {
        printf("Enter the amount you paid: ");
        read_word_count = scanf("%f", &amount_paid);
        if (read_word_count <= 0) {
            fprintf(stderr, "Invalid amount entered\n");
            flush_buffer();
        }
        amount_paid_cent = currency_to_cents(amount_paid);
    } while (read_word_count <= 0);

    amount_in_change = amount_paid_cent - amount_owed_cent;
    if (amount_in_change < 0) printf("Amount paid is less than amount owed. No change.\n");
    else {
        mkchange(tender, amount_in_change);
        printchange(tender);
    }

    freetender(tender);

    flush_buffer();
    printf("Enter 'q' to quit or any other key to go again: ");
    if (getchar() != 'q') return main();
    else return 0;
}

int currency_to_cents(float currency) {
    return (int)floor(currency * 100.);
}

void printchange(Tender *tender) {
    int i = 0;
    int total_change = 0;
    float actual_change = 0.;

    for (; i < NUM_TENDER; ++i) {
        printf("%s = %d\n", 
                tender->num_tender[i] != 1 ? PLURAL_TENDER_NAMES[i] : SINGULAR_TENDER_NAMES[i], 
                tender->num_tender[i]);
        total_change += tender->num_tender[i] * tender->tender_values[i];
    }

    actual_change = ((float)total_change) / 100.0;
    printf("Total change: %.2f\n", actual_change);
}

void mkchange(Tender *tender, int change) {
    int i = NUM_TENDER - 1;

    for (; i >= 0; --i) {
        tender->num_tender[i] = (change / tender->tender_values[i]);
        change -= tender->tender_values[i] * tender->num_tender[i];
    }
}

Tender *mktender() {
    Tender *tender = malloc(sizeof(Tender));
    memmove(&tender->tender_values, TENDER_VALUES, sizeof(TENDER_VALUES));
    memset(&tender->num_tender, 0, sizeof(NUM_TENDER));
    return tender;
}

void freetender(Tender *tender) {
    free(tender);
}

void flush_buffer() {
    volatile char c;
    while ((c = getchar()) != '\n' || c != EOF);
}
