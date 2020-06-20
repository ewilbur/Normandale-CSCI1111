#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef void (*run_io)(void);

extern void page380_3(void);
extern void page380_6(void);
extern void page380_8(void);
extern void page380_9(void);


void do_exit(void);
void flush_buffer(void);
int prompt_user(const char *prompt);
void print_menu(void);
run_io get_problem(int);

int main() {
    run_io user_problem = NULL;
    int user_problem_number = 0;

    while (true) {
        user_problem_number = prompt_user("Select a problem to run or enter 'q' to quit: ");
        user_problem = get_problem(user_problem_number);
        if (user_problem != NULL) user_problem();
        else fprintf(stderr, "error: invalid selection");
    }
}

void do_exit() {
    printf("Goodbye!\n");
    exit(EXIT_SUCCESS);
}

run_io get_problem(int problem_number) {
    switch (problem_number) {
        case 1: return page380_3;
        case 2: return page380_6;
        case 3: return page380_8;
        case 4: return page380_9;
        case 'q' - '0': return do_exit;
        default: return NULL;
    }
}

int prompt_user(const char *prompt) {
    char problem_number_choice = 0;
    print_menu();
    printf("%s\n", prompt);
    problem_number_choice  = getchar() - '0';
    flush_buffer();
    return problem_number_choice;
}

void print_menu() {
    static const int problem_numbers[] = {        3,         6,         8,         9};
    static const size_t NUM_OPTIONS    = sizeof(problem_numbers) / sizeof(int);
    int i;
    for (i = 0; i < NUM_OPTIONS; ++i)
        printf("%d ---- page380_%d\n", i + 1, problem_numbers[i]);
}

void flush_buffer() {
    while (getchar() != '\n')
        ;
}
