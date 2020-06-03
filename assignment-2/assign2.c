/*
  Assignment #2
  CSCI 1111-10

  Complete the functions to solve
  problems 2, 3, 6, & 7 on pages 97 
  from the Prata book. 

*/

#include <stdio.h>
#include <stdlib.h>

#define grams_of_water_per_quart 950.
#define mass_of_water_molecule 3.0e-23
#define centimeters_per_inch 2.54

void page97_2(void);
void page97_3(void);
void page97_6(void);
void page97_7(void);


int main() {
    printf("Solution to page 97 #2\n");
    page97_2();

    printf("Solution to page 97 #3\n");
    page97_3();
    
    printf("Solution to page 97 #6\n");
    page97_6();

    printf("Solution to page 97 #7\n");
    page97_7();

#if defined(WIN32) || defined (_WIN32) || defined(__WIN32__) || defined(__NT__)
    system("pause"); //dos specific
#else
    getchar();
#endif
    return 0;
}

void page97_2(void) {
    int user_ascii_number = 0;
    printf("Enter an ASCII code value as a decimal: ");
    scanf("%d", &user_ascii_number);
    printf("ASCII value %d has representation %c\n", user_ascii_number, (char) user_ascii_number);
    printf("\n");
    return;
}

void page97_3(void) {
    printf("\aStartled by the sudden sound, Sally shouted,\n");
    printf("\"By the Great Pumpkin, what was that!\"\n");
    printf("\n");
    return;
}

void page97_6(void) {
    double amount_of_water;
    double num_water_molecules = 0;
    printf("Enter an amount of water in quarts: ");
    scanf("%lf", &amount_of_water);
    num_water_molecules = (amount_of_water * grams_of_water_per_quart) / mass_of_water_molecule;
    printf("There are about %lf molecules of water in %lf quarts of water", num_water_molecules, amount_of_water);
    printf("\n");
    return;
}

void page97_7(void) {
    double num_inches;
    printf("Enter a height in inches: ");
    scanf("%lf", &num_inches);
    printf("%lf inches is %lf centimeters", num_inches, num_inches * centimeters_per_inch);
    printf("\n");
    return;
}
