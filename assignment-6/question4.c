#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void sieve(size_t);

void page296_9() {
    size_t user_bound;
    printf("Enter an upper bound: ");
    scanf("%lu", &user_bound);
    sieve(user_bound + 1);
}

/* Simple prime sieve. Runs in n*sqrt(n)
 */
void sieve(size_t bound) {
    unsigned char *primer = (unsigned char *)calloc(bound, sizeof(unsigned char));
    primer[0] = primer[1] = 1;
    size_t i, j;
    for (i = 2; i <= sqrt(bound); ++i) {
        if (primer[i] == 0) {
            for (j = 2; j * i < bound; ++j)
                primer[i * j] = 1;
            printf("%lu\n", i);
        }
    }

    for (; i < bound; ++i)
        if (primer[i] == 0)
            printf("%lu\n", i);
    free(primer);
}
