#include <stdio.h>
#include <stdlib.h>

#define MIN_DOUBLE(D1, D2) ((D1) < (D2) ? (D1) : (D2))

extern void flush_buffer();

void reorder(double *d1, double *d2, double *d3);
void page380_6(void);
void swap(double *d1, double *d2);

void page380_6(void) {
    double d1, d2, d3;
    printf("Enter a double: ");
    scanf("%lf", &d1);
    printf("Enter a double: ");
    scanf("%lf", &d2);
    printf("Enter a double: ");
    scanf("%lf", &d3);
    printf("d1 = %lf\td2 = %lf\td3 = %lf\n", d1, d2, d3);
    reorder(&d1, &d2, &d3);
    printf("d1 = %lf\td2 = %lf\td3 = %lf\n", d1, d2, d3);
    flush_buffer();
}

void swap(double *d1, double *d2) {
    double t = *d1;
    *d1 = *d2;
    *d2 = t;
}

void reorder(double *d1, double *d2, double *d3) {
    if (*d1 > *d2) swap(d1, d2);
    if (*d2 > *d3) swap(d2, d3);
    if (*d1 > *d2) swap(d1, d2);
}
