/*
 * @program two_func.c
 * @author Evan Wilbur
 * @course CSCI 1111
 * @semester Summer 2020
 * @description Textbook example of forward declaration of function. Two
 *              functions in this file. This is copied from the textbook. 
 */
#include <stdio.h>

void butler(void);

int main(void) {
    printf("I will summon the butler function.\n");
    butler();
    printf("Yes. Bring me some tea and writeable DVDs.\n");
    return 0;
}

void butler(void) {
    printf("You rang, sir?\n");
}
