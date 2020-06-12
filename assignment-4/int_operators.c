/*
 * @author Evan Wilbur
 * @class CSCI 1111
 * @section 10
 * @description Basic math quiz generator using C integers. Written completely
 *              from scratch to make it more modular. Furthermore, bugs from
 *              the original (ie. infinite loops upon non-integer entry and
 *              invalid selections) were removed. Additionally, made ranges
 *              more customizable by declaring them as constants at the
 *              beginning of the file.
 */

#define NUM_TESTS 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/* Type semigroup is a binary function that takes in two ints and returns
 * an int
 */
typedef int (*int_semigroup)(int, int);

int get_rand(int, int); /* ^ Generate a random in within the range (inclusive) */
int prompt_menu(); /* Print the menu to the user and return the selection */

/* Possible semigroups operators */
int integer_add(int, int);
int integer_sub(int, int);
int integer_mul(int, int);
int integer_div(int, int);
int integer_mod(int, int);

void get_operands(char, int*, int*); /* ^ Returns the operand values for a problem
                                      * based on the operation being done and the
                                      * ranged defined in the constants
                                      */

char integer_semigroup_symbol_from_choice(int);
int_semigroup integer_semigroup_from_symbol(char);

void run_integer_test(int choice);
void flush_buffer(); /* ^ Remove invalid input from the buffer */
void invalid_selection();


/* Default range */
static const int def_op1_lb = 20;
static const int def_op1_ub = 67;
static const int def_op2_lb =  2;
static const int def_op2_ub = 25;

/* Division range */
static const int div_op1_lb = 20;
static const int div_op1_ub = 67;
static const int div_op2_lb =  2;
static const int div_op2_ub = 25;

/* Modulus range */
static const int mod_op1_lb = 20;
static const int mod_op1_ub = 67;
static const int mod_op2_lb =  2;
static const int mod_op2_ub = 25;

/* Addition range */
static const int add_op1_lb = 20;
static const int add_op1_ub = 67;
static const int add_op2_lb =  2;
static const int add_op2_ub = 25;

/* Multiplication range */
static const int mul_op1_lb = 20;
static const int mul_op1_ub = 67;
static const int mul_op2_lb =  5;
static const int mul_op2_ub = 25;

/* Subtraction range */
static const int sub_op1_lb = 20;
static const int sub_op1_ub = 67;
static const int sub_op2_lb =  2;
static const int sub_op2_ub = 25;


int main() {
    while (true) {
        int choice = prompt_menu();
        if (choice == 0) break;
        else if (choice == -1) continue;
       run_integer_test(choice);
    }
    printf("Goodbye!\n");
    return 0;
}

int prompt_menu() {
    int choice = -1;
    printf("What would you like to be tested on?\n");
    printf("1 integer division operator\n");
    printf("2 integer modulus operator\n");
    printf("3 integer addition operator\n");
    printf("4 integer multiplication operator\n");
    printf("5 integer subtraction operator\n");
 	printf("0 to quit\n");

    if (scanf("%d", &choice) <= 0) {
        invalid_selection();
        return prompt_menu();
    }
    return choice;
}

int get_rand(int lb, int ub) {
    static bool rand_seeded = false;
    int random_int_range = ub - lb + 1;

    if (!rand_seeded) {
#if defined(DEVEL)
        srand(0);
#else
        srand(time(0));
#endif
        rand_seeded = true;
    }

    return (rand() % random_int_range) + lb;
}

/* Possible integer semigroups for jump-table */

int integer_add(int op1, int op2) {
    return op1 + op2;
}

int integer_sub(int op1, int op2) {
    return op1 - op2;
}

int integer_mul(int op1, int op2) {
    return op1 * op2;
}

int integer_div(int op1, int op2) {
    return op1 / op2;
}

int integer_mod(int op1, int op2) {
    return op1 % op2;
}

/* Match the user choice to a semigroup symbol */
char integer_semigroup_symbol_from_choice(int choice) {
    switch (choice) {
        case 1  : return '/';
        case 2  : return '%';
        case 3  : return '+';
        case 4  : return '*';
        case 5  : return '-';
        default : return 'q';
    }
}

/* Return the semigroup function from a given symbol */
int_semigroup integer_semigroup_from_symbol(char symbol) {
    switch (symbol) {
        case '/' : return integer_div;
        case '%' : return integer_mod;
        case '+' : return integer_add;
        case '*' : return integer_mul;
        case '-' : return integer_sub;
        default  : return NULL;
    }
}

/* Generate the random operands from a given symbol. This could be way shorter
 * if every operand was given the same range of valeus to be taken from.
 * However, since addition has a different range I decided to make every range
 * customizable. See the static consts at the top of this file to adjust the
 * possible ranges
 */

void get_operands(char symbol, int *op1, int *op2) {
    int op1_lb, op1_ub, op2_lb, op2_ub;
    switch (symbol) {
        case '/' :
            op1_lb = div_op1_lb;
            op1_ub = div_op1_ub;
            op2_lb = div_op2_lb;
            op2_ub = div_op2_ub;
            break;
        case '%' :
            op1_lb = mod_op1_lb;
            op1_ub = mod_op1_ub;
            op2_lb = mod_op2_lb;
            op2_ub = mod_op2_ub;
            break;
        case '+' :
            op1_lb = add_op1_lb;
            op1_ub = add_op1_ub;
            op2_lb = add_op2_lb;
            op2_ub = add_op2_ub;
            break;
        case '*' :
            op1_lb = mul_op1_lb;
            op1_ub = mul_op1_ub;
            op2_lb = mul_op2_lb;
            op2_ub = mul_op2_ub;
            break;
        case '-' :
            op1_lb = sub_op1_lb;
            op1_ub = sub_op1_ub;
            op2_lb = sub_op2_lb;
            op2_ub = sub_op2_ub;
            break;
        default  :
            op1_lb = def_op1_lb;
            op1_ub = def_op1_ub;
            op2_lb = def_op2_lb;
            op2_ub = def_op2_ub;
            break;
    }
    *op1 = get_rand(op1_lb, op1_ub);
    *op2 = get_rand(op2_lb, op2_ub);
}

void run_integer_test(int choice) {
    const int num_tests = NUM_TESTS;
    int i = 0;
    int num_correct = 0;

    char symbol = integer_semigroup_symbol_from_choice(choice);
    int_semigroup semigroup = integer_semigroup_from_symbol(symbol);

    if (semigroup == NULL) {
        invalid_selection();
        return;
    }
    for (i = 0; i < num_tests; ++i) {
        int user_answer;
        int op1;
        int op2;
        int answer = 0;

        get_operands(symbol, &op1, &op2);
        answer = semigroup(op1, op2);

        printf("%d %c %d = ? ", op1, symbol, op2);

        while (scanf("%d", &user_answer) <= 0) {
            invalid_selection();
            printf("%d %c %d = ? ", op1, symbol, op2);
        }
        if (answer == user_answer) {
            num_correct++;
            printf("Correct!\n\n");
        } else
            printf("Sorry, the correct answer = %d\n\n", answer);
    }
    printf("You scored %d out of 10\n", num_correct);
}

void flush_buffer() {
    while (getchar() != '\n');
}

void invalid_selection() {
    printf("Not a valid selection.\n");
    flush_buffer();
}
