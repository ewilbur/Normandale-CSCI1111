#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void sieve(unsigned long long int);

void page296_9() {
    unsigned long long int user_bound = 0;
    printf("Enter an upper bound: ");
    scanf("%llu", &user_bound);
    sieve(user_bound + 1);
}

/* Simple prime sieve. Runs in n*sqrt(n)
 */
void sieve(unsigned long long int bound) {
    unsigned char *primer = (unsigned char *)calloc(bound, sizeof(unsigned char));
    primer[0] = primer[1] = 1;
    unsigned long long int i, j;
    double cap = sqrt(bound);
    for (i = 2; i <= cap; ++i) {
        if (primer[i] == 0) {
            for (j = 2; j * i < bound; ++j)
                primer[i * j] = 1;
            printf("%llu", i);
            printf("\n");
        }
    }

    for (; i < bound; ++i)
        if (primer[i] == 0) {
            printf("%llu", i);
            printf("\n");
        }
    free(primer);
}
