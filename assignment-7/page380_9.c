#include <math.h>
#include <stdio.h>
#include <stdlib.h>

extern void flush_buffer(void);

void page380_9();
static double power(double b, int e);

void page380_9() {
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
    if (b == 0 && e == 0) return NAN;
    if (b == 0) return 0;
    if (e == 0) return 1;
    if (e == 2) return b * b;
    if (e < 0) return 1 / power(b, -e);
    return power(power(b, e / 2), 2) * ((e % 2 == 0) ? 1 : b);
}
