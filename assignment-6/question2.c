#include <stdlib.h>
#include <stdio.h>

void page296_3(void) {
    size_t num_even = 0, num_odd = 0;
    int average_even = 0, average_odd = 0;
    int user_int;
    printf("Enter characters, seperated by a newline. When you are done, enter '0'.\n");
    scanf("%d", &user_int);
    while (user_int != 0) {
        if (user_int % 2 == 0) {
            ++num_even;
            average_even += user_int;
        }
        else {
            ++num_odd;
            average_odd += user_int;
        }
        scanf("%d", &user_int);
    }

    printf("     | Total entered |   Average\n");
    printf("---------------------------------\n");
    printf("Even | %13lu | %lf\n", num_even, (double)average_even / (double)num_even);
    printf("Odd  | %13lu | %lf\n", num_odd, (double)average_odd / (double) num_odd);
}

