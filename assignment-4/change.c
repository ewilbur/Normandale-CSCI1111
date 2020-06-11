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

#define DEVELOPMENT
#define TENDER_STRING_LENGTH 32
#define DEFAULT_BUFFER_SIZE 32

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
    int tender[NUM_TENDER];
} Tender;

int get_user_cents(const char *, size_t);
int parse_tender_string(const char *);
void mkchange(Tender *, int);
void render_tender(Tender *);
char *strip_whitespace(char *);
void flush_buffer();
void handle_overflow();

int main() {
    /* | Let the max BUFFER to hold the user input be the default size */
    const size_t USER_INPUT_BUFFER_SIZE = DEFAULT_BUFFER_SIZE;
    /* | Container to store the tender values of the change due */
    Tender change_owed;
    int user_paid_cents = 0;
    int user_owed_cents = 0;

    /* | Initialize the change owed to zero */
    memset(&change_owed, 0, sizeof(change_owed));

    /* | Prompt the user a message and store the parse cent input into their
     * respective variables
     */
    user_owed_cents = get_user_cents("Enter the amount you owed: ",
                                     USER_INPUT_BUFFER_SIZE);
    user_paid_cents = get_user_cents("Enter the amount you paid: ",
                                     USER_INPUT_BUFFER_SIZE);

    if (user_paid_cents < user_owed_cents)
        /* ^ Can't make change if you paid less than you owe. */
        printf("Cannot make change_owed. You did not give enough\n");
    else {
        /* ^ Otherwise, calculate the change and the bills/coins to pay it */
        mkchange(&change_owed, user_paid_cents - user_owed_cents);
        /* | And print it out */
        render_tender(&change_owed);
    }

    /* | Prompt the user if they want to go again */
    printf("\nPress 'q' to quit. Otherwise, press any character to go again: ");
    if (getchar() == 'q')
        return 0;
    /* TODO Make this into a do-while loop instead of a recursive call */
    return main();
}

/* | Prompts the user to enter a monetary value, parses it, and returns the
 *   parsed result. If there is an error parsing or allocating the memory to
 *   store the user input, return -1.
 */
int get_user_cents(const char *prompt, size_t buffer_size) {
    char *currency_str = (char*)malloc(sizeof(char) * buffer_size);
    void *free_temp = currency_str;
    int currency_amount = 0;

    /* | Return error if no memory can be allocated for the user input */
    if (currency_str == NULL) return -1;

    do {
        /* ^ Print the prompt, get the input from the user. If there was too
         * many character inputs, print an error message, truncate the input,
         * and flush the rest of the buffer. If parsing fails, prompt for input
         * again until successful parse.
         */
        printf("%s", prompt);
        fgets(currency_str, buffer_size, stdin);
        if (strnlen(currency_str, buffer_size) == buffer_size - 1) {
            fprintf(stderr,
                    "error: input overflow - truncating string to %s\n",
                    currency_str);
            handle_overflow();
        }
        currency_str = strip_whitespace(currency_str);
        currency_amount = parse_tender_string(currency_str);
        if (currency_amount < 0) {
            fprintf(stderr,
                    "error: invalid input on currency amount: %s\n",
                    currency_str);
        }
    } while (currency_amount < 0);

    free(free_temp);
    return currency_amount;
}

/* | Print the change owed */
void render_tender(Tender *tender) {
    if (tender == NULL) return;

    size_t i = 0;
    /* | Running total of change */
    int total = 0;

    for (; i < NUM_TENDER; ++i) {
        printf("%s = %d\n", SINGULAR_TENDER_NAMES[i], tender->tender[i]);
        total += tender->tender[i] * TENDER_VALUES[i];
    }

    printf("Total change = %d.%02d\n", total / 100, total % 100);
}

void mkchange(Tender *change, int total) {
    if (change == NULL) return;
    if (total < 0) return;

    int *change_rear = change->tender + (NUM_TENDER - 1);
    const int *value_rear  = TENDER_VALUES + (NUM_TENDER - 1);

    while (change->tender <= change_rear) {
        *change_rear = total / *value_rear;
        total %= *value_rear;
        --change_rear;
        --value_rear;
    }
}

int parse_tender_string(const char *tender) {
    if (tender == NULL) return -1;

    size_t i = 0, j = 0;
    int tender_total = 0;

    while (tender[i + j] != '\0') {
        /* ^ We haven't reached the end of the input string */
        if (tender[i + j] == '.' && j == 0) {
            /* ^ Encountered the first decimal (if it exists) */
            /* | Move to the right of the decimal */
            j = 1;
            /* | If it happens to be the end of the string, break out of the
             * loop
             */
            if (tender[i + j] == '\0') break;
        }
        if (!isdigit(tender[i + j]) || j >= 3)
            /* ^ Error if we encounter a non-digit or we are three places after
             * the decimal
             */
            return -1;
        tender_total *= 10;
        tender_total += tender[i + j] - '0';
        /* Increment i if we haven't encountered a decmial. Otherwise j */
        j == 0 ? ++i : ++j;
    }
    if (j == 0)
        j = 1;
    return tender_total * pow(10, 3 - j);
}

char *strip_whitespace(char *str) {
    /* | Can't strip whitespace of a NULL string */
    if (str == NULL) return NULL;

    const size_t USER_INPUT_BUFFER_SIZE = DEFAULT_BUFFER_SIZE;
    /* | Pointer to the end of the string */
    char *end = str + strnlen(str, USER_INPUT_BUFFER_SIZE) - 1;

    while (isspace(*end) && str < end)
        end--;
    while (isspace(*str) && str < end)
        str++;
    end[1] = '\0';
    return str;
}

void flush_buffer() {
    while (getchar() != '\n');
}

void handle_overflow() {
    flush_buffer();
}
