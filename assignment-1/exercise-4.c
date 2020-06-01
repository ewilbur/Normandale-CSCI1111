#include <stdio.h>

int main(void) {
    int i = 0;
    for (; i < 3; ++i, printf("For he's a jolly good fellow!\n"))
        ;
    printf("Which nobody can deny!\n");
    return 0;
}
