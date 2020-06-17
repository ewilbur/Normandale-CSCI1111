#include <stdio.h>

static const double BASIC_RATE = 10;
static const double OVERTIME_MULTIPLIER = 1.5;
static const size_t OVERTIME_HOURS = 40;
static const double TAX_RATE_300 = 0.15;
static const double TAX_RATE_450 = 0.20;
static const double TAX_RATE_REST = 0.25;

double calculate_tax(double pay) {
    double total_tax = 0.0;
    
    if (pay > 300) {
        total_tax += TAX_RATE_300 * 300;
        pay -= 300;
    } else {
        total_tax += TAX_RATE_300 * pay;
        goto return_tax_rate;
    }
    if (pay > 150) {
        total_tax += TAX_RATE_450 * 150;
        pay -= 150;
    } else {
        total_tax += TAX_RATE_450 * pay;
        goto return_tax_rate;
    }
    total_tax += TAX_RATE_REST * pay;
return_tax_rate:
    return total_tax;
}

double gross_pay( double basic_rate,
                  size_t basic_hours,
                  double overtime_rate,
                  size_t overtime_hours) {
    return (basic_rate * basic_hours) + (overtime_rate * overtime_hours);
}

double take_home_pay( double basic_rate,
                      size_t basic_hours,
                      double overtime_rate,
                      size_t overtime_hours) {
    double total_pay = gross_pay(basic_rate, basic_hours, overtime_rate, overtime_hours);
    return total_pay - calculate_tax(total_pay);
}

void page296_7() {
    size_t normal_hours = 0;
    size_t overtime_hours = 0;
    double total_pay = 0.;

    printf("Enter the number of hours you worked this week: ");
    scanf("%lu", &normal_hours);
    if (normal_hours > OVERTIME_HOURS) {
        overtime_hours = normal_hours - OVERTIME_HOURS;
        normal_hours = OVERTIME_HOURS;
    }
    
    printf("Gross pay: %.2lf\n",
            total_pay = gross_pay(BASIC_RATE,
                                  normal_hours, 
                                  (BASIC_RATE * OVERTIME_MULTIPLIER),
                                  overtime_hours));

    printf("Taxes: %.2lf\n", calculate_tax(total_pay));

    printf("Net pay: %.2lf\n", total_pay - calculate_tax(total_pay));
}
