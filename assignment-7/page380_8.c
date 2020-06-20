#include <math.h>
#include <stdio.h>
#include <stdlib.h>

extern void flush_buffer(void);

void page380_8();
static double power(double b, int e);

void page380_8() {
    double base;
    int expon;
    printf("Enter a double for the base: ");
    scanf("%lf", &base);
    printf("Enter an integer for the exponenet: ");
    scanf("%d", &expon);
    printf("%lf\n", power(base, expon));
    flush_buffer();
}

double power(double b, int e) {
    double res = 1;
    if (b == 0 && e == 0) return NAN;
    if (b == 0) return 0;
    if (e == 0) return 1;
    if (e < 0) return 1 / power(b, -e);
    for (; e != 0; --e) res *= b;
    return res;
}
