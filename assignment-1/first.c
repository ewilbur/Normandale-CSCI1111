/*
 * @program first.c
 * @author Evan Wilbur
 * @course CSCI 1111
 * @semester Summer 2020
 * @description First program written for CSCI 1111. This is copied verbatim 
 *              from the textbook. Apparently, the purpose of this program is
 *              only test to see if we can compile the program? Well, it
 *              compiled. Removed the comments from the original because they
 *              seemed a bit unnecessary.
 */
#include <stdio.h>

int main(void) {
    int num;
    num = 1;

    printf("I am a simple ");
    printf("computer.\n");
    printf("My favorite number is %d because it is first.\n", num);

    printf("Press any character to continue");
    getchar();
    return 0;
}

/*
 * I am a simple computer.
 * My favorite number is 1 because it is first.
 * Press any character to continue
 */
