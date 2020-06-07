/*
 * @author Evan Wilbur
 * @due 9 June 2020
 * @class CSCI 1111
 * @professor Kevin Lee
 * @date 6 June 2020
 * @description A collection of problems from the C Primer Plus book that were
 *              to be completed. Basics of IO.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

#define STD_BUFFER_SIZE 256

void page141_2(void);
void page141_3(void);
void page141_4(void);
void page141_7(void);


int main()
{
    printf("Solution to page 141 #2\n");
    page141_2();

    printf("Solution to page 141 #3\n");
    page141_3();
    
    printf("Solution to page 141 #4\n");
    page141_4();
    

    printf("Solution to page 141 #7\n");
    page141_7();

    /* C really needs to get off it's ass and fix this buffered newline issue */
    getchar();
    getchar();
    return 0;

}

void page141_2(void) {
    const size_t buffer_size = STD_BUFFER_SIZE;
    char user_name[buffer_size];
    char altered_name[buffer_size];
    size_t index = 0;

    memset(user_name, 0, sizeof(user_name));
    memset(altered_name, 0, sizeof(altered_name));

    printf("Enter your first name: ");
    scanf("%s", user_name);

    /* Enclosed in quotes */
    printf("Your name enclosed in quotes: \"%s\"\n", user_name);

    /* Field 20 char wide. Right justified */
    index = strlen(user_name) > 20 ? 0 : 20 - strlen(user_name);
    memset(altered_name, '.', 20);
    altered_name[20] = '\0';
    strncpy(altered_name + index, user_name, buffer_size - index);
    printf("Field of 20 char, right justified: \"%s\"\n", altered_name);

    /* Field 20 char wide. Left justified */
    strncpy(altered_name, user_name, 20);
    for (index = strlen(altered_name); index < 20; ++index)
        altered_name[index] = '.';
    altered_name[index] = '\0';
    printf("Field of 20 char, left justified:  \"%s\"\n", altered_name);

    /* Three characters wider */
    printf("Name in field three chars wider: ..%s.\n\n", user_name);
}

void page141_3(void) {
    double user_double;
    printf("Enter a floating point number: ");
    scanf("%lf", &user_double);
    
    printf("The input is %lf or %e\n\n", user_double, user_double);
}

void page141_4(void) {
    const size_t buffer_size = STD_BUFFER_SIZE;
    char user_name[buffer_size];
    float user_inches;

    printf("Enter a height in inches: ");
    scanf("%f", &user_inches);

    printf("Enter your name: ");
    scanf("%s", user_name);

    printf("%s, you are %f feet tall\n\n", user_name, user_inches / 12);
}


void page141_7(void) {
    const double third_d = 1.0 / 3.0;
    const float  third_f = 1.0 / 3.0;

    printf("Four digits: %.4f\n", third_d);
    printf("Twelve digits: %.12f\n", third_d);
    printf("Sixteen digits: %.16f\n", third_d);

    printf("FLT_DIG: %d\n", FLT_DIG);
    printf("DBL_DIG: %d\n\n", DBL_DIG);
}
