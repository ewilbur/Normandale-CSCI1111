#include <stdlib.h>
#include <stdio.h>

void page296_1() {
    char ch;
    size_t num_newlines = 0, num_spaces = 0, num_else = 0;
    while ((ch = getchar()) != '#') {
        switch (ch) {
            case '\n': 
                ++num_newlines;
                break;
            case ' ':
                ++num_spaces;
                break;
            default:
                ++num_else;
                break;
        }
    }
    printf("%s|%s|%s\n", "Space Count", "Newline Count", "Other Characters");
    printf("------------------------------------------\n");
    printf("%5lu      |%7lu      |%9lu\n", num_spaces, num_newlines, num_else);
}
