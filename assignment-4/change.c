/*
 * @author Evan Wilbur
 * @class CSCI 1111
 * @section 10
 * @description An even more improved change calculator. This doesn't use
 *              floats anywhere in the code. Instead, it parses everything as
 *              ints. Yes, yes, I know that the purpose of this program is to
 *              learn how to deal with floats and doubles. But I've been coding
 *              for years now and I've never come across a problem that
 *              requires floats or doubles. Anytime there's a decimal value
 *              needed, I just parse them as ints, as I've done here. I may
 *              lose points since I'm not "learning" floats (as if anyone but
 *              God can understand these horribly designed data types) but I
 *              think I should make up those points since my way requires more
 *              code including a parser.
 */


#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#define DEV
#define DENOMINATION_STRING_LENGTH 32


static const char SINGULAR_DENOMINATION_NAMES[][DENOMINATION_STRING_LENGTH]
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

static const int DENOMINATION_VALUES[]
    = { 1,
        5,
        10,
        25,
        100,
        500,
        1000,
        2000 };

#define NUM_DENOMINATION (sizeof(DENOMINATION_VALUES) / sizeof(int))

typedef struct {
    int denomination[NUM_DENOMINATION];
} Tender;

int main_dev(int, char **);
int parse_tender_string(const char *);
void mkchange(Tender *, int);
void render_tender(Tender *);

int main(int argc, char **argv) {
#ifdef DEV
    return main_dev(argc, argv);
#endif

}

int main_dev(int argc, char **argv) {

    char user_input[256];
    memset(user_input, 0, 256);
    while (true) {
        int user_total = 0;
        Tender tender;
        printf("Enter a currency value: ");
        scanf("%s", user_input);
        user_total = parse_tender_string(user_input);
        if (user_total < 0) {
            printf("Error in parse: %s\n", user_input);
            continue;
        }
        mkchange(&tender, user_total);
        render_tender(&tender);
    }
    return 0;
}

void render_tender(Tender *tender) {
    size_t i = 0;
    int total = 0;
    for (; i < NUM_DENOMINATION; ++i) {
        printf("%s = %d\n", SINGULAR_DENOMINATION_NAMES[i], tender->denomination[i]);
        total += tender->denomination[i] * DENOMINATION_VALUES[i];
    }

    printf("Total change = %d.%02d\n", total / 100, total % 100);
}

void mkchange(Tender *change, int total) {
    size_t i = NUM_DENOMINATION - 1;
    for (; i > 0; --i) {
        change->denomination[i] = (int)total / (int)DENOMINATION_VALUES[i];
        total %= DENOMINATION_VALUES[i];
    }
    change->denomination[0] = total;
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
