/* 
 * @program fathm_ft.c
 * @author Evan Wilbur
 * @course CSCI 1111
 * @semester Summer 2020
 * @description This program is copied from the textbook. Little to nothing is
 *              changed from the original. This program converts 6 feet to
 *              fathoms.
 */
#include <stdio.h>

int main(void) {
    int feet, fathoms;

    fathoms = 2;
    feet = 6 * fathoms;
    printf("There are %d feet in %d fathoms!\n", feet, fathoms);
    printf("Yes, I said %d feet!\n", 6 * fathoms);

    printf("Press any character to continue");
    getchar();
    return 0;
}
/*
 * There are 12 feet in 2 fathoms!
 * Yes, I said 12 feet!
 * Press any character to continue
 */
