#include <stdlib.h>
#include <stdio.h>

void page296_3(void) {
    size_t num_even = 0, num_odd = 0;
    int average_even = 0, average_odd = 0;
    int user_int;
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

    printf("     | Total entered | Average\n");
    printf("------------------------------\n");
    printf("Even | %7lu       | %f\n", num_even, (float)average_even / (float)num_even);
    printf("Odd  | %7lu       | %f\n", num_odd, (float)average_odd / (float) num_odd);
    while (getchar() != '\n');
}

