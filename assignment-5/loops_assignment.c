/*
        CSCI 1111

        Loop Assignment (Guaranteed to drive you loopy!)
        Your assigment is to fill in the following functions
        with loops that will output the given output!(Listed as
        a comment at the end of the program)

         You may have to count up or count down or even nest the loops.

        Good Luck!

*/

#include <stdlib.h>
#include <stdio.h>


void loop_1(void);
void loop_2(void);
void loop_3(void);
void loop_4(void);
void loop_5(void);
void loop_6(void);
void loop_7(void);
void loop_8(void);
void loop_9(void);



int main() {

    printf("Problem 1\n");
    loop_1();

    printf("Problem 2\n");
    loop_2();

    printf("Problem 3\n");
    loop_3();

    printf("Problem 4\n");
    loop_4();

    printf("Problem 5\n");
    loop_5();

    printf("Problem 6\n");
    loop_6();

    printf("Problem 7\n");
    loop_7();

    printf("Problem 8\n");
    loop_8();

    printf("Problem 9\n");
    loop_9();

#if defined (_WIN32) || defined (_WIN64)
    system("pause");
#else
    printf("Press any key to continue . . .");
    getchar();
#endif
	return EXIT_SUCCESS;
}

void loop_1(void) {
  int i;
  for (i = 1; i <= 20; ++i)
      printf("%3d", i);
  printf("\n\n");
}

void loop_2(void) {
    int i = 105;
    while (i -= 5)
        printf("%3d", i);
    printf("\n\n");
}

void loop_3(void) {
    char c = 'A';
    do {
        printf("%2c", c);
        ++c;
    } while (c <= 'Z');

    printf("\n\n");
}

void loop_4(void) {
    char c = 'Z';
    while (c >= 'A') {
        printf("%2c", c);
        c -= 2;
    }
    printf("\n\n");
}

void loop_5(void) {
    int i, j;

    for (i = 1; i < 5; ++i) {
        for (j = 1; j < 10; ++j) {
            printf("(%d,%d) ", i, j);
        }
        printf("\n");
    }
    printf("\n");
}

void loop_6(void) {
    int i, j;
    for (i = 1; i < 5; ++i) {
        for (j = 1; j < 10; ++j) {
            printf("%5d", i * j);
        }
        printf("\n");
    }
    printf("\n");
}

void loop_7(void) {
    int i, j;
    for (i = 1; i < 21; ++i) {
        for (j = i; j > 0; --j) {
            printf("%3d", j);
        }
        printf("\n");
    }
    printf("\n");
}

void loop_8(void) {
    int i, j;
    for (i = 0; i < 16; ++i) {
        for (j = 3; j >= 0; --j) {
            putchar(((i >> j) & 1) + '0');
        }
        printf("\n");
    }
    printf("\n");
}

void loop_9(void) {
    int i, j;

    for (i = 0x1; i < 0x10; ++i) {
        for (j = 0x1; j < 0x10; ++j) {
            printf("%5X", i * j);
        }
        printf("\n");
    }
    printf("\n");
}


/*
Problem 1
  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20

Problem 2
100 95 90 85 80 75 70 65 60 55 50 45 40 35 30 25 20 15 10  5

Problem 3
 A B C D E F G H I J K L M N O P Q R S T U V W X Y Z

Problem 4
 Z X V T R P N L J H F D B

Problem 5
(1,1) (1,2) (1,3) (1,4) (1,5) (1,6) (1,7) (1,8) (1,9)
(2,1) (2,2) (2,3) (2,4) (2,5) (2,6) (2,7) (2,8) (2,9)
(3,1) (3,2) (3,3) (3,4) (3,5) (3,6) (3,7) (3,8) (3,9)
(4,1) (4,2) (4,3) (4,4) (4,5) (4,6) (4,7) (4,8) (4,9)

Problem 6
    1    2    3    4    5    6    7    8    9
    2    4    6    8   10   12   14   16   18
    3    6    9   12   15   18   21   24   27
    4    8   12   16   20   24   28   32   36

Problem 7
  1
  2  1
  3  2  1
  4  3  2  1
  5  4  3  2  1
  6  5  4  3  2  1
  7  6  5  4  3  2  1
  8  7  6  5  4  3  2  1
  9  8  7  6  5  4  3  2  1
 10  9  8  7  6  5  4  3  2  1
 11 10  9  8  7  6  5  4  3  2  1
 12 11 10  9  8  7  6  5  4  3  2  1
 13 12 11 10  9  8  7  6  5  4  3  2  1
 14 13 12 11 10  9  8  7  6  5  4  3  2  1
 15 14 13 12 11 10  9  8  7  6  5  4  3  2  1
 16 15 14 13 12 11 10  9  8  7  6  5  4  3  2  1
 17 16 15 14 13 12 11 10  9  8  7  6  5  4  3  2  1
 18 17 16 15 14 13 12 11 10  9  8  7  6  5  4  3  2  1
 19 18 17 16 15 14 13 12 11 10  9  8  7  6  5  4  3  2  1
 20 19 18 17 16 15 14 13 12 11 10  9  8  7  6  5  4  3  2  1

Problem 8
0000
0001
0010
0011
0100
0101
0110
0111
1000
1001
1010
1011
1100
1101
1110
1111

Problem 9
    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
    2    4    6    8    A    C    E   10   12   14   16   18   1A   1C   1E
    3    6    9    C    F   12   15   18   1B   1E   21   24   27   2A   2D
    4    8    C   10   14   18   1C   20   24   28   2C   30   34   38   3C
    5    A    F   14   19   1E   23   28   2D   32   37   3C   41   46   4B
    6    C   12   18   1E   24   2A   30   36   3C   42   48   4E   54   5A
    7    E   15   1C   23   2A   31   38   3F   46   4D   54   5B   62   69
    8   10   18   20   28   30   38   40   48   50   58   60   68   70   78
    9   12   1B   24   2D   36   3F   48   51   5A   63   6C   75   7E   87
    A   14   1E   28   32   3C   46   50   5A   64   6E   78   82   8C   96
    B   16   21   2C   37   42   4D   58   63   6E   79   84   8F   9A   A5
    C   18   24   30   3C   48   54   60   6C   78   84   90   9C   A8   B4
    D   1A   27   34   41   4E   5B   68   75   82   8F   9C   A9   B6   C3
    E   1C   2A   38   46   54   62   70   7E   8C   9A   A8   B6   C4   D2
    F   1E   2D   3C   4B   5A   69   78   87   96   A5   B4   C3   D2   E1
*/
