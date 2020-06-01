/*
 * @program nogood.c
 * @author Evan Wilbur
 * @course CSCI 1111
 * @semester Summer 2020
 * @description Bug fix example from the textbook. The original bugged code was
 *              commented out with the proper syntax and logic written below it.
 *              Other comments attempt to explain what was changed and what the
 *              bug was.
 */
#include <stdio.h>

int main(void) {
    /* | Syntax error*/
    /* int n, int n2, int n3; */
    int n, n2, n3; /* ^ Proper syntax */
    n = 5;
    n2 = n * n;
    n3 = n2 * n2;
    /* | Logic error */
    /* printf("n = %d, n squared = %d, n cubed = &d\n", n, n2, n3); */
     printf("n = %d, n squared = %d, n to the forth = %d\n", n, n2, n3);
     /* ^ The correct operation being done here is raising to the forth power, not the third.*/
    printf("Press any character to continue");
    getchar();
    return 0;
}
