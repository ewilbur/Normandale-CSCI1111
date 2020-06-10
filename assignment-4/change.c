/*
 * @author Evan Wilbur
 * @class CSCI 1111
 * @section 10
 * @description An improved calculator. Seperate data structure to store the
 *              change. Hopefully this allows the program to be more extendible
 *              if different coins are required (eg fifty cent coin). If the
 *              need for higher denominations is required, simply add to
 *              TENDER_VALUES. The only important thing to keep in mind is that
 *              the names and values in SINGLUAR_TENDER_NAMES,
 *              PLURAL_TENDER_NAMES, and TENDER_VALUES must correlate. As in,
 *              the index of each must be consistent otherwise the program
 *              fails.
 */


#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#define DEV
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

int main_dev(int, char **);
bool validate_currency_input(const char *);
int read_currency_string(const char *);

int main(int argc, char **argv) {
#ifdef DEV
    return main_dev(argc, argv);
#endif
}

int main_dev(int argc, char **argv) {
    return 0;
}

int read_currency_string(const char *tender) {
}

bool validate_currency_input(const char *tender) {
    size_t i = 0;
    size_t j = 0;
    /* Check that each char before the decimal is a digit */
    while (tender[i] != '\0' && tender[i] != '.') {
        if (!isdigit(tender[i])) return false;
        ++i;
    }
    if (tender[i] == '\0') return false;
    /* Otherwise, we have to make sure:
     *  a) There are exactly two chars after the decimal
     *  b) Each of those two chars are digits
     */
    for (j = 1; j < 3; ++j) {
        if (tender[i + j] == '\0') return false;
        if (!isdigit(tender[i + j])) return false;
    }
    /* After checking two placed after the decimal point (see above) if we've
     * reached the end of the input then the input is valid
     */
    return tender[i + j] == '\0';
}
