#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void sieve(size_t);


/* | This is to fix a bug that took over three hours to find. Basically,
 *   when reading a unsigned long long int from a function called via a
 *   returned pointer, the variable gets underflowed and causes undefined
 *   brehavior. It is fixed if you initialize the variable first to zero
 *   or if you put in the correct formatting string for scanf. Here we do
 *   both
 */
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
const char format_string[] = "%llu";
#else
const char format_string[] = "%lu";
#endif

void page296_9() {
    size_t user_bound = 0;
    printf("Enter an upper bound: ");
    scanf(format_string, &user_bound);
    sieve(user_bound + 1);
}

/* Simple prime sieve. Runs in n*sqrt(n)
 */
void sieve(size_t bound) {
    unsigned char *primer = (unsigned char *)calloc(bound, sizeof(unsigned char));
    primer[0] = primer[1] = 1;
    size_t i, j;
    double cap = sqrt(bound);
    for (i = 2; i <= cap; ++i) {
        if (primer[i] == 0) {
            for (j = 2; j * i < bound; ++j)
                primer[i * j] = 1;
            printf(format_string, i);
            printf("\n");
        }
    }

    for (; i < bound; ++i)
        if (primer[i] == 0) {
            printf(format_string, i);
            printf("\n");
        }
    free(primer);
}
