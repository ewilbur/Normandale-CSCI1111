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
    return 0;
}
