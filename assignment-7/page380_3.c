#include <stdio.h>
#include <stdlib.h>

extern void flush_buffer(void);

void page380_3(void);
void print_char_box(char c, int col, int row);

void page380_3() {
    char c;
    int row, col;
    printf("Enter a character: ");
    c = getchar();
    printf("Enter number of rows: ");
    scanf("%d", &row);
    printf("Enter number of columns: ");
    scanf("%d", &col);
    print_char_box(c, col, row);
    flush_buffer();
}

void print_char_box(char c, int col, int row) {
    int i, j;
    for (i = 0; i < row; ++i) {
        for (j = 0; j < col; ++j)
            putchar(c);
        putchar('\n');
    }
}
