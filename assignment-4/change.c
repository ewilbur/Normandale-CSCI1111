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
int parse_tender_string(const char *);

int main(int argc, char **argv) {
#ifdef DEV
    return main_dev(argc, argv);
#endif
}

int main_dev(int argc, char **argv) {

    char user_input[256];
    memset(user_input, 0, 256);
    while (true) {
        printf("enter a currency value: ");
        scanf("%s", user_input);
        printf("Converted: %d\n", parse_tender_string(user_input));
    }
    return 0;
}

/* Parse a string containing a currency value. If the parse fails, returns -1.
 * Acceptable currency formats:
 *      a) 0.XX
 *      b) XX...X.XX
 *      c) XX...X
 *      d) .XX
 *      e) 0.XX
 *      f) XX...X.X
 */
int parse_tender_string(const char *tender) {
    size_t i = 0, j = 0;
    int tender_total = 0;
    while (tender[i + j] != '\0') {
        if (tender[i + j] == '.' && j == 0) j = 1;
        if (tender[i + j] == '\0') break;
        if (!isdigit(tender[i + j]) || j >= 3) return -1;
        tender_total *= 10;
        tender_total += tender[i + j] - '0';
        j == 0 ? ++i : ++j;
    }
    if (j == 0) j = 1;
    return tender_total * pow(10, 3 - j);
}
