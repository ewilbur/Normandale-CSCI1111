#include <stdio.h>

typedef void (*run_io)(void);

extern void page296_1(void);
extern void page296_3(void);
extern void page296_7(void);
extern void page296_9(void);

run_io prompt_selection();

int main() {
    do {
        prompt_selection()();
        while (getchar() != '\n');
        printf("Go again (y/n)?\n");
    } while (getchar() != 'n');
    printf("Goodbye!\n");
    return 0;
}

run_io prompt_selection() {
    int user_selection = 0;
    printf("1 -- problem 1\n");
    printf("3 -- problem 3\n");
    printf("7 -- problem 7\n");
    printf("9 -- problem 9\n\n");
    printf("Which problem would you like to run? ");
    scanf("%d", &user_selection);
    switch (user_selection) {
        case 1: return page296_1;
        case 3: return page296_3;
        case 7: return page296_7;
        case 9: return page296_9;
        default:
            printf("Invalid selection! Pick again\n");
            return prompt_selection();
    }
}
