/* Evan Wilbur
 * 
 *
 * Quick calculator using a jump-table. This isn't perfect. For example, there
 * is no buffer-length check so there's a potential for buffer overflow.
 *
 * Also, since I'm developing this in a bash terminal, I got lazy and decided
 * to just use 'x' for multiplication. The only other two appropriate options
 * ('.' and '*') are bash control characters and result in bad parses. Rather
 * than take the time and make this more platform-agnostic, I decided to just
 * not allow those characters and only accept 'x' for multiplication.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const int BUFFER_SIZE = 100;

typedef float (*operation)(float, float);

float __add(float, float);
float __sub(float, float);
float __div(float, float);
float __mul(float, float);
operation get_operation(char);

int main(int argc, char **argv) {
    float f1, f2;
    char op = 0;
    operation operator = NULL;
    char buffer[BUFFER_SIZE];

    if (argc == 1 || argc > 4) {
        fprintf(stderr, "error: invalid number of arguments: %d\n", argc - 1);
        exit(EXIT_FAILURE);
    }
    memset(buffer, 0, sizeof(char) * BUFFER_SIZE);

    for (int i = 1; i < argc; ++i) {
        strcat(buffer, argv[i]);
    }

    sscanf(buffer, "%f %c %f", &f1, &op, &f2);
    operator = get_operation(op);
    if (operator == NULL) {
        fprintf(stderr, "error: invalid operator symbol: %c", op);
        exit(EXIT_FAILURE);
    }
    printf("%f %c %f = %f\n", f1, op, f2, operator(f1, f2));
}

float __add(float x, float y) {
    return x + y;
}

float __sub(float x, float y) {
    return x - y;
}

float __div(float x, float y) {
    return x / y; /* Retuns NAN if y == 0 */
}

float __mul(float x, float y) {
    return x * y;
}

operation get_operation(char c) {
    switch (c) {
        case '+': return __add;
        case '-': return __sub;
        case '/': return __div;
        case 'x': return __mul;
        default: fprintf(stderr, "error: invalid symbol (%c)\n", c);
                 exit(EXIT_FAILURE);
    }
}
